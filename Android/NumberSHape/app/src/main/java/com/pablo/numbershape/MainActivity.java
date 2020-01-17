package com.pablo.numbershape;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.EditText;
import android.widget.Toast;


public class MainActivity extends AppCompatActivity {
    class Number{
        int numb;
        public boolean trick(){
            int x=1;
            int  trickNum=1;
            while(trickNum < numb){
                x++;
                trickNum=trickNum+x;
            }
            if(trickNum==numb){
                return true;
            }else{
                return false;
            }
        }
        public boolean quad(){
            double squad=  Math.sqrt(numb);

            if(squad == Math.floor(squad)){

                return true;

            }else{
                return false;
            }
        }
    }
public void calc(View view) {
    EditText number = findViewById(R.id.number);
    String msm = "";
    if (number.getText().toString().isEmpty()) {
        msm = "ERROR";
    } else {
    Number n = new Number();
    n.numb = Integer.parseInt(number.getText().toString());


        if (n.quad()) {
        msm = "Quad";

        if (n.trick()) {
            msm = "TRICK and SQUAD";
        }
    } else if (n.trick()) {
        msm = "TRICK ";

    } else {
        msm = "NAN";
    }
}
    Toast.makeText(getApplicationContext(),msm, Toast.LENGTH_LONG).show();


}
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }
}
