package com.example.bearingsd;


import androidx.appcompat.app.AppCompatActivity;

import android.app.ProgressDialog;
import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.bluetooth.BluetoothManager;
import android.bluetooth.BluetoothSocket;
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

    private TextView hover;
    private TextView inTest;
    BluetoothAdapter myBluetooth;
    BluetoothSocket btSocket;
    private boolean isBtConnected = false;
    private ProgressDialog progress;
    private Set<BluetoothDevice> btDevs;
    private TextView btAdd;
    InputThread streamRead;
    private InputStream btInput;
    private OutputStream btOutput;
    private SeekBar earlBar;
    String hcAddress;
    static final UUID myUUID = UUID.fromString("00001101-0000-1000-8000-00805F9B34FB");

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Global Instantiations
        hover = findViewById(R.id.heightDesire);
        myBluetooth = BluetoothAdapter.getDefaultAdapter();
        btDevs = myBluetooth.getBondedDevices();


        btAdd = findViewById(R.id.btAdd);
        inTest = findViewById(R.id.testInput);
        earlBar = findViewById(R.id.earlBar);

        // Set default height to latched
        hover.setText("0.0");
    }

    public void hoverDown(View view) {
        //TextView hover = (TextView) findViewById(R.id.heightDesire);
        double hovF = Double.valueOf(hover.getText().toString());

        if (hovF <= 1.1) {
            hovF += .1;
            hovF = Math.round(hovF*100.0)/100.0;
            String hovS = String.valueOf(hovF);
            hover.setText(hovS);
        }
    }

    public void hoverUp(View view) {
        //TextView hover = (TextView) findViewById(R.id.heightDesire);
        double hovF = Double.valueOf(hover.getText().toString());
        if (hovF > 0) {
            hovF -= .1;
            if (hovF < 0) {
                hovF = 0.0;
            }
            hovF = Math.round(hovF*100.0)/100.0;
            String hovS = String.valueOf(hovF);
            hover.setText(hovS);
        }

    }

    public void latchPlate(View view) {
        //TextView hover = (TextView) findViewById(R.id.heightDesire);
        hover.setText("0.0");
    }

    public void checkConnection(View view) {
        for (BluetoothDevice bluetoothDevice : btDevs = myBluetooth.getBondedDevices()) {
            if (bluetoothDevice.getName().equals("HC-05")) {
                hcAddress = bluetoothDevice.toString();
                btAdd.setText(hcAddress);
                // Open Connection to bt device and socket
                if (!isBtConnected)
                    new ConnectBT().execute();
                else {
                    try {
                        if (btSocket != null && btSocket.isConnected()) {
                            isBtConnected = false;
                            //streamRead.stop();
                            btSocket.close();
                            btSocket = null;
                            Toast.makeText(getApplicationContext(), "Socket closed", Toast.LENGTH_SHORT).show();
                        }
                    } catch (IOException e) {
                        Toast.makeText(getApplicationContext(), "Failed to close Socket", Toast.LENGTH_SHORT).show();
                    }
                }

            }
        }
    }

    public void startRead(View view) {
        streamRead = new InputThread();
        streamRead.start();
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
            int isBufEmpty = 0;
            int bufInt;
            while(isBtConnected) {
                try {
                    // Read from Input stream 4 bytes
                    Thread.sleep(20);
                    if (btSocket != null && btSocket.isConnected())
                        isBufEmpty = btInput.read(buf,0,inBytes);
                    bbuf = ByteBuffer.wrap(buf);
                    bbuf.order(ByteOrder.LITTLE_ENDIAN);
                    bufInt = bbuf.getInt();
                    if (isBufEmpty > -1 && bufInt > 200 && bufInt < 4000) {
                        inTest.setText(Integer.toString(bufInt));
                        earlBar.setProgress((bufInt-200)/38);
                    }

                } catch (IOException e) {
                    Toast.makeText(getApplicationContext(),"Error while reading",Toast.LENGTH_SHORT).show();
                } catch (InterruptedException e) {
                    Toast.makeText(getApplicationContext(),"Error while sleeping",Toast.LENGTH_SHORT).show();
                }
            }
        }
    }
}

