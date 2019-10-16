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
import android.widget.Switch;
import android.widget.TextView;
import android.widget.Toast;
import java.io.IOException;
import java.util.Set;
import java.util.UUID;

public class MainActivity extends AppCompatActivity {

    private TextView hover;
    BluetoothAdapter myBluetooth;
    BluetoothSocket btSocket;
    private Set<BluetoothDevice> btDevs;
    private TextView btAdd;
    static final UUID myUUID = UUID.fromString("00001101-0000-1000-8000-00805F9B34FB");

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Global Instantiations
        hover = findViewById(R.id.heightDesire);
        locAdp = BluetoothAdapter.getDefaultAdapter();
        btDevs = locAdp.getBondedDevices();
        btAdd = findViewById(R.id.btAdd);

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
        for (BluetoothDevice bluetoothDevice : btDevs = locAdp.getBondedDevices()) {
            if (bluetoothDevice.getName().equals("HC-05")) {
                btAdd.setText(bluetoothDevice.toString());

            }

        }
        ;
        
        
    }

    private class ConnectBT extends AsyncTask<Void, Void, Void> {
        private boolean ConnectSuccess = true;

        @Override
        protected  void onPreExecute () {
            progress = ProgressDialog.show(ledControl.this, "Connecting...", "Please Wait!!!");
        }

        @Override
        protected Void doInBackground (Void... devices) {
            try {
                if ( btSocket==null || !isBtConnected ) {
                    myBluetooth = BluetoothAdapter.getDefaultAdapter();
                    BluetoothDevice dispositivo = myBluetooth.getRemoteDevice(address);
                    btSocket = dispositivo.createInsecureRfcommSocketToServiceRecord(myUUID);
                    BluetoothAdapter.getDefaultAdapter().cancelDiscovery();
                    btSocket.connect();
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
                msg("Connection Failed. Is it a SPP Bluetooth? Try again.");
                finish();
            } else {
                msg("Connected");
                isBtConnected = true;
            }

            progress.dismiss();
        }
    }
}
