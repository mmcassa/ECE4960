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

    private int latchHeight = -1;
    // Height References
    private int heightRef = 0;
    private double curHeight = 0.0;
    private int range = 5;
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
    private TextView btAdd;
    private TextView earlHeight;
    private TextView hover;
    private SeekBar seekBars;
    private Button upButton;
    private Button downButton;
    private Button latchButton;

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

        // Set default height to latched
        hover.setText("-");
        upButton.setClickable(false);
        downButton.setClickable(false);
        latchButton.setClickable(false);
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
        if (!latched) {
            if (curHeight <= 120) {
                setBtOutput(view, lower);

                curHeight += .1;
                curHeight = Math.round(curHeight * 100.0) / 100.0;
                String hovS = String.valueOf(curHeight);
                hover.setText(hovS);
            }
        }
    }

    public void hoverUp(View view) {
        //TextView hover = (TextView) findViewById(R.id.heightDesire);
        //double hovF = Double.valueOf(hover.getText().toString());
        if (!latched) {
            if (curHeight > -25) {
                curHeight -= .1;
                if (curHeight < 0) {
                    curHeight = 0.0;
                } else {
                    setBtOutput(view, raise);
                }
                curHeight = Math.round(curHeight * 100.0) / 100.0;
                String hovS = String.valueOf(curHeight);
                hover.setText(hovS);
            }
        }
    }

    public void latchPlate(View view) {
        //TextView hover = (TextView) findViewById(R.id.heightDesire);
        if (latchHeight < 0) {
            setBtOutput(view, latch);
            hover.setText("LATCHED");
        } else {
            setBtOutput(view, latch);
            latchHeight = -1;
            hover.setText(Double.toString(curHeight));
        }
    }

    public void checkConnection(View view) {
        // If not connected attempt connect
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

            } catch (IOException e) {
            //catch (Exception e) {
                Toast.makeText(getApplicationContext(), "Failed to close Socket", Toast.LENGTH_SHORT).show();
            }
        }
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
                    btOutput.write(latch);
                    btOutput.write(0x30);
                    latched = true;
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
        int inBytes = 4;
        byte[] buf = new byte[inBytes];
        ByteBuffer bbuf;

        @Override
        public void run() {
            String heightTxt;
            int isBufEmpty = 0;
            int bufInt;
            double accuracy;

            int barSelect = 1;
            seekBars = findViewById(R.id.arleBar);

            try {
                btInput.skip(btInput.available() % 12);
            } catch (IOException e) {
                Toast.makeText(getApplicationContext(),"Skip error.",Toast.LENGTH_LONG).show();
            }

            while(isBtConnected) {
                try {
                    // Read from Input stream 4 bytes
                    while(isBtConnected && btSocket.isConnected() &&  btInput.available() < inBytes) {
                    }
                    if (isBtConnected && btSocket != null && btSocket.isConnected()) {
                        isBufEmpty = btInput.read(buf, 0, inBytes);
                    } else {
                        if (!isBtConnected || !(btSocket.isConnected()))
                            break;
                        isBufEmpty = 0;
                    }

                    if (isBufEmpty == 4) {
                        bbuf = ByteBuffer.wrap(buf);
                        bbuf.order(ByteOrder.LITTLE_ENDIAN);
                        bufInt = bbuf.getInt();
                        if (bufInt < 0 || bufInt > 30) {
                            if (isBtConnected && btSocket != null)
                                btInput.skip(7);
                            else {
                                Toast.makeText(getApplicationContext(), "Error while ubf skip 1", Toast.LENGTH_SHORT).show();
                                break;
                            }
                        } else {
                            accuracy = (bufInt - heightRef);
                            if (accuracy != 0.0)
                                accuracy /= range;

                            if (Math.abs(accuracy) <= .1)
                                seekBars.setThumb(getDrawable(R.drawable.thumb_green));
                            else if (Math.abs(accuracy) <= .2)
                                seekBars.setThumb(getDrawable(R.drawable.thumb_yellow));
                            else
                                seekBars.setThumb(getDrawable(R.drawable.custom_thumb));


                            if (accuracy >= 1)
                                seekBars.setProgress(95);
                            else if (accuracy <= -1)
                                seekBars.setProgress(-95);
                            else
                                seekBars.setProgress((int) (accuracy*100));

                            heightTxt = ((double) bufInt/10) + " mm";//+ Integer.toHexString(bufInt);
                            earlHeight.setText(heightTxt);

                            if (++barSelect == 4) {
                                barSelect = 1;
                                seekBars = findViewById(R.id.arleBar);
                                earlHeight = findViewById(R.id.arleHeight);
                            } else if (barSelect == 2) {
                                seekBars = findViewById(R.id.earlBar);
                                earlHeight = findViewById(R.id.earlHeight);
                            } else {
                                seekBars = findViewById(R.id.lareBar);
                                earlHeight = findViewById(R.id.lareHeight);
                            }
                        }
                    } else {
                        if (isBtConnected && btSocket != null)
                            btInput.skip(inBytes-isBufEmpty+8);
                        else {
                            Toast.makeText(getApplicationContext(),"Error while buf skip",Toast.LENGTH_SHORT).show();
                            break;
                        }
                    }

                } catch (IOException e) {
                    Toast.makeText(getApplicationContext(),"Error while reading",Toast.LENGTH_SHORT).show();
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
            }
        }
    }
}

