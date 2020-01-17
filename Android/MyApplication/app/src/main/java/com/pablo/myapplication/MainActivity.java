package com.pablo.myapplication;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {
 int cont=1;
 public void clickFunctio(View view){
     EditText  meuTexto = (EditText) findViewById(R.id.meuTexto) ;
     EditText  senha = (EditText) findViewById(R.id.senha) ;
     String user ="Pablo";
     String passord ="1234";
     ImageView image = (ImageView) findViewById(R.id.img);

     if(meuTexto.getText().toString().equalsIgnoreCase( user)){

         if(senha.getText().toString().equalsIgnoreCase(passord)){
             Toast.makeText(MainActivity.this,"Conected",Toast.LENGTH_LONG).show();
             image.setImageResource(R.drawable.black);


         }else {
             Toast.makeText(MainActivity.this,"Senha invalida",Toast.LENGTH_LONG).show();
             image.setImageResource(R.drawable.tv);

         }
     }else{
         Toast.makeText(MainActivity.this,"ERROR",Toast.LENGTH_LONG).show();
         image.setImageResource(R.drawable.error);

     }

     /*
     switch (cont){
         case 1:
             Log.i("tentativa",meuTexto.getText().toString()+": "+cont);
             ++cont;
             break;
         case 2:
             Log.i("tentativa",meuTexto.getText().toString()+": "+cont);
             ++cont;
             break;
         case 3:
             Log.i("tentativa",meuTexto.getText().toString()+": "+cont);
             ++cont;
             break;
         case 4:
             Log.i("tentativa",meuTexto.getText().toString()+": "+cont);
             cont=1;
             break;

     }
     */
 }
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }
}
