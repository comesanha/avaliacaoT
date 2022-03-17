package com.example.ndktest

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.TextView

class MainActivity : AppCompatActivity() {
    public native String HelloWorld();
    static{
        System.loadLibrary("ndktest");
    }
    override fun onCreate(savedInstanceState: Bundle?) {

        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        ((TextView)findViewById(R.id.text_hello_world)).setText(HelloWorld());
    }
}