package com.pablo.calculadora;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {
    public void popUp (String string){
        Toast.makeText(MainActivity.this, string,Toast.LENGTH_LONG).show();
    }
    public void conv (View view) {
        int random = (int)(Math.random() * 20+0);
        EditText ding = (EditText) findViewById(R.id.ding);
        int y = Integer.parseInt(ding.getText().toString());
        if(random < y){
            popUp("Maior que "+ random);

        }else if (random >y){
            popUp("Menor que "+ random);

        }else{
            popUp("Igual a "+ random);

        }


    }
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }
}
