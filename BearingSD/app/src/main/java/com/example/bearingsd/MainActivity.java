package com.example.bearingsd;
import androidx.appcompat.app.AppCompatActivity;
import androidx.drawerlayout.widget.DrawerLayout;

import android.app.ProgressDialog;
import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.bluetooth.BluetoothManager;
import android.bluetooth.BluetoothSocket;
import android.graphics.drawable.Drawable;
import android.os.AsyncTask;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.FrameLayout;
import android.widget.SeekBar;
import android.widget.Switch;
import android.widget.TextView;
import android.widget.Toast;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.nio.ByteBuffer;
import java.nio.ByteOrder;
import java.util.Set;
import java.util.UUID;


public class MainActivity extends AppCompatActivity {

    // Command bytes
    private static byte latch = 0x33;
    private static byte lower = 0x31;
    private static byte raise = 0x32;

    // Height References
    private int heightRef = 0;
    private int range = 5;

    private double curHeight = 0.0;

    private boolean latched = false;
    // Bluetooth universals
    private boolean isBtConnected = false;
    BluetoothAdapter myBluetooth;
    BluetoothSocket btSocket;
    private InputStream btInput;
    private OutputStream btOutput;
    private ProgressDialog progress;
    String hcAddress;
    static final UUID myUUID = UUID.fromString("00001101-0000-1000-8000-00805F9B34FB");
    private Set<BluetoothDevice> btDevs;

    // App layout objects
    private FrameLayout monitorFrame;
    private FrameLayout adjustLayout;
    private TextView btAdd;
    private TextView earlHeight;
    private TextView hover;
    private SeekBar seekBars;
    private Button upButton;
    private Button downButton;
    private Button latchButton;
    private TextView massText;
    private TextView massTitle;
    // Classes
    InputThread streamRead;




    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        setContentView(R.layout.activity_main);

        // Global Instantiations

        myBluetooth = BluetoothAdapter.getDefaultAdapter();
        btDevs = myBluetooth.getBondedDevices();

        hover = findViewById(R.id.heightDesire);
        btAdd = findViewById(R.id.btAdd);
        earlHeight = findViewById(R.id.earlHeight);
        upButton = findViewById(R.id.moveUpButton);
        downButton = findViewById(R.id.moveDownButton);
        latchButton = findViewById(R.id.latchButton);
        massText = findViewById(R.id.massText);
        massTitle = findViewById(R.id.massTitle);
        monitorFrame = findViewById(R.id.monitorFrame);
        adjustLayout = findViewById(R.id.adjustFrame);

        // Set default height to latched
        hover.setText("-");
        upButton.setClickable(false);
        downButton.setClickable(false);
        latchButton.setClickable(false);
    }

    public void changeLayout() {
        if (isBtConnected) {
            monitorFrame.setVisibility(FrameLayout.VISIBLE);
            adjustLayout.setVisibility(FrameLayout.VISIBLE);
        } else {
            monitorFrame.setVisibility(FrameLayout.GONE);
            adjustLayout.setVisibility(FrameLayout.INVISIBLE);
        }
    }
    public void setBtOutput(View view,byte change) {
        try {
            btSocket.getOutputStream().write(change);
            btSocket.getOutputStream().write(0x30);
        } catch (IOException e) {
            Toast.makeText(getApplicationContext(),"Last message not sent",Toast.LENGTH_SHORT).show();
        }
    }

    public void hoverDown(View view) {
        //TextView hover = (TextView) findViewById(R.id.heightDesire);
        //double hovF = Double.valueOf(hover.getText().toString());
        //if (!latched) {
            if (curHeight <= 120) {
                setBtOutput(view, lower);

                curHeight += .1;
                curHeight = Math.round(curHeight * 100.0) / 100.0;
                String hovS = String.valueOf(curHeight);
                //hover.setText(hovS);
            }
        //}
    }

    public void hoverUp(View view) {
        //TextView hover = (TextView) findViewById(R.id.heightDesire);
        //double hovF = Double.valueOf(hover.getText().toString());
        //if (!latched) {
            if (curHeight >= -25) {
                curHeight -= .1;
                if (curHeight <= -24) {
                    curHeight = 0.0;
                } else {
                    setBtOutput(view, raise);
                }
                curHeight = Math.round(curHeight * 100.0) / 100.0;
                String hovS = String.valueOf(curHeight);
                //hover.setText(hovS);
            }
        //}
    }

    public void latchPlate(View view) {

        if (!latched) {
            setBtOutput(view, latch);
            hover.setText("LOCK");
            latched = true;
        } else {
            setBtOutput(view, latch);
            hover.setText(Double.toString(curHeight));
            latched = false;
        }
    }

    public void checkConnection(View view) {

        if(!isBtConnected) {
            for (BluetoothDevice bluetoothDevice : btDevs = myBluetooth.getBondedDevices()) {
                if (bluetoothDevice.getName().equals("HC-05")) {
                    hcAddress = bluetoothDevice.toString();

                    // Open Connection to bt device and socket
                    //if (!isBtConnected) {
                    new ConnectBT().execute();

                }
            }
        // If connected attempt disconnect
        } else {
            try {
                isBtConnected = false;
                btSocket.close();
                btSocket = null;
                btInput = null;
                btOutput = null;
                Toast.makeText(getApplicationContext(), "Socket closed", Toast.LENGTH_SHORT).show();
                upButton.setClickable(false);
                downButton.setClickable(false);
                latchButton.setClickable(false);
                btAdd.setText("Disconnected");
                hover.setText("-");
                curHeight = 0.0;
            } catch (IOException e) {
            //catch (Exception e) {
                Toast.makeText(getApplicationContext(), "Failed to close Socket", Toast.LENGTH_SHORT).show();
            }
        }
        //changeLayout();
    }

    private class ConnectBT extends AsyncTask<Void, Void, Void> {
        private boolean ConnectSuccess = true;

        @Override
        protected  void onPreExecute () {
            progress = ProgressDialog.show(MainActivity.this, "Connecting...", "Please Wait!!!");
        }

        @Override
        protected Void doInBackground (Void... devices) {
            try {
                if ( btSocket==null || !isBtConnected ) {
                    myBluetooth = BluetoothAdapter.getDefaultAdapter();
                    BluetoothDevice hcDevice = myBluetooth.getRemoteDevice(hcAddress);
                    btSocket = hcDevice.createInsecureRfcommSocketToServiceRecord(myUUID);
                    BluetoothAdapter.getDefaultAdapter().cancelDiscovery();
                    btSocket.connect();
                    btInput = btSocket.getInputStream();
                    btOutput = btSocket.getOutputStream();
                }
            } catch (IOException e) {
                ConnectSuccess = false;
            }

            return null;
        }

        @Override
        protected void onPostExecute (Void result) {
            super.onPostExecute(result);

            if (!ConnectSuccess) {
                Toast.makeText(getApplicationContext(),"Connection Failed",Toast.LENGTH_SHORT).show();
            } else {
                Toast.makeText(getApplicationContext(),"Connected",Toast.LENGTH_SHORT).show();
                isBtConnected = true;
                btAdd.setText("Connected to HC-05");
                streamRead = new InputThread();
                streamRead.start();
                try {
                    btOutput.write(0x30);
                } catch (IOException e) {
                    Toast.makeText(getApplicationContext(),"Failed to send initial latch",Toast.LENGTH_SHORT).show();
                }

                upButton.setClickable(true);
                downButton.setClickable(true);
                latchButton.setClickable(true);
            }

            progress.dismiss();
        }
    }

    private class InputThread extends Thread {
        int inBytes = 8;
        byte[] buf = new byte[inBytes];
        ByteBuffer bbuf;

        @Override
        public void run() {
            int isBufEmpty = 0;
            int bufInt;

            while(isBtConnected) {
                try {
                    // Read from Input stream 4 bytes
                    while(isBtConnected && btSocket.isConnected() &&  btInput.available() < (inBytes)) {
                    }
                    if (isBtConnected && btSocket != null && btSocket.isConnected()) {
                        isBufEmpty = btInput.read(buf, 0, inBytes);
                    } else {
                        if (!isBtConnected || !(btSocket.isConnected()))
                            break;
                        isBufEmpty = 0;
                    }

                    if (isBufEmpty == inBytes) {
                        bbuf = ByteBuffer.wrap(buf);
                        bbuf.order(ByteOrder.LITTLE_ENDIAN);
                        bufInt = bbuf.getInt();
                        if (bufInt == 0 || bufInt % 100000 != 0 || !(bufInt / 100000 >= 1 || bufInt / 100000 <= 5)) {
                            if (isBtConnected && btSocket != null && btSocket.isConnected()) {
                                if (isBtConnected && btSocket.isConnected() && btInput.available() >= 1) {
                                    btInput.skip(1);
                                }

                                if (!btAdd.getText().equals("Syncing..."))
                                    btAdd.setText("Syncing...");
                                //Toast.makeText(getApplicationContext(),"Misread",Toast.LENGTH_SHORT).show();
                            } else {
                                isBtConnected = false;
                                Toast.makeText(getApplicationContext(), "Error while reading.", Toast.LENGTH_SHORT).show();
                                break;
                            }
                        } else {
                                if (!btAdd.getText().equals("Connected"))
                                    btAdd.setText("Connected");
                                switch (bufInt / 100000) {
                                    case 1:
                                        updateSeek((SeekBar) findViewById(R.id.arleBar),(TextView) findViewById(R.id.arleHeight),bbuf.getInt());
                                        break;
                                    case 2:
                                        updateSeek((SeekBar) findViewById(R.id.earlBar),(TextView) findViewById(R.id.earlHeight),bbuf.getInt());
                                        break;
                                    case 3:
                                        updateSeek((SeekBar) findViewById(R.id.lareBar),(TextView) findViewById(R.id.lareHeight),bbuf.getInt());
                                        break;
                                    case 4:
                                        verifyFloat(bbuf.getInt());
                                        break;
                                    case 5:
                                        updateMass(bbuf.getInt());
                                        break;
                                    default:
                                        bbuf.clear();
                                        break;
                                }
                                //massTitle.setText(bufInt/100000);
                        }
                    } else {
                        if (isBtConnected && btSocket != null)
                            Toast.makeText(getApplicationContext(),"Misread",Toast.LENGTH_SHORT).show();
                        else {
                            Toast.makeText(getApplicationContext(),"Error while buf skip",Toast.LENGTH_SHORT).show();
                            break;
                        }
                    }

                } catch (IOException e) {
                    Toast.makeText(getApplicationContext(),"Error while reading",Toast.LENGTH_SHORT).show();
                    break;
                }

            }
            if (isBtConnected) {
                isBtConnected = false;
                btSocket = null;
                btInput = null;
                btOutput = null;
                Toast.makeText(getApplicationContext(), "Socket closed", Toast.LENGTH_SHORT).show();
                upButton.setClickable(false);
                downButton.setClickable(false);
                latchButton.setClickable(false);
                btAdd.setText("Disconnected");
                //changeLayout();
            }
        }

        private void updateMass(int bufMass) {
            if (bufMass < 9999 && bufMass > -9999) {
                String mText = bufMass + " g";
                massText.setText(mText);
            } //else {
                //massText.setText("Err");
            //}
        }

        private void updateSeek(SeekBar bar, TextView barText, int bufHeight) {
            double accuracy = bufHeight - (curHeight*10);
            String heightTxt;

            /*
            if (accuracy != 0.0) {
                accuracy /= range;
            }

            // Set thumb color
            if (Math.abs(accuracy) <= .1)
                bar.setThumb(getDrawable(R.drawable.thumb_green));
            else if (Math.abs(accuracy) <= .2)
                bar.setThumb(getDrawable(R.drawable.thumb_yellow));
            else
                bar.setThumb(getDrawable(R.drawable.custom_thumb));

            // Set bar progress
            if (accuracy >= .83)
                seekBars.setProgress(83);
            else if (accuracy <= -.83)
                seekBars.setProgress(-83);
            else
                seekBars.setProgress((int) (accuracy * 100));
            */
            // Set bar text
            if (bufHeight != 0) {
                if (bufHeight > -10 && bufHeight < 50)
                    heightTxt = (((double) bufHeight) / 10) + " mm";//+ Integer.toHexString(bufInt);
                else
                    heightTxt = (String) barText.getText();//"Err";

            } else
                heightTxt = "0.0 mm";

            if (!heightTxt.equals(barText.getText()))
            barText.setText(heightTxt);



        }

        private void verifyFloat(int bufHeight) {
            String heightTxt;
            //if (bufHeight < 0)
            if (bufHeight < 40 && bufHeight > -11) {
                //heightTxt = ((double)bufHeight/10) + " mm";
                if (bufHeight != -10) {
                    if (bufHeight != 0)
                        curHeight = ((double) bufHeight) / 10;
                    else
                        curHeight = 0.0;
                    latched = false;
                    heightTxt = Double.toString(curHeight);
                    if (!heightTxt.equals(hover.getText()))
                        hover.setText(heightTxt);
                } else {
                    if (!latched)
                        latched = true;
                    hover.setText("LOCK");

                }
            } /*else {
                if (!hover.getText().equals("~"+Double.toString(curHeight)) || !hover.getText().equals("~LOCK"))
                    if(!latched)
                        hover.setText("~"+Double.toString(curHeight));
                    else
                        hover.setText("~LOCK");
            }*/
        }


    } // End class
}

