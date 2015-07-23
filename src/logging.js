package com.getpebble.dataloggingtest;

import android.app.Activity;
import android.content.Context;
import android.os.Bundle;
import android.widget.TextView;

import com.getpebble.android.kit.PebbleKit;
import com.getpebble.android.kit.PebbleKit.PebbleDataLogReceiver;

import java.util.UUID;

/**
 * MainActivity class
 * Implements a PebbleDataLogReceiver to process received log data, 
 * as well as a finished session.
 */
public class MainActivity extends Activity {

  // Configuration
  private static final UUID WATCHAPP_UUID = UUID.fromString("07f33a80-5209-4fc4-aeaf-a2983e4a7710");
  private static final int DATA_LOG_TAG_COMPASS = 52;

  // App elements
  private PebbleDataLogReceiver dataloggingReceiver;
  private TextView textView;
  private StringBuilder resultBuilder = new StringBuilder();

  @Override
  protected void onCreate(Bundle savedInstanceState) {
    super.onCreate(savedInstanceState);
    setContentView(R.layout.activity_main);

    // Setup TextView
    textView = (TextView)findViewById(R.id.text_view);
    textView.setText("Waiting for logging data...");
  }

  @Override
  protected void onResume() {
    super.onResume();

    // Define data reception behavior
    PebbleDataLogReceiver dataloggingReceiver = new PebbleDataLogReceiver(WATCHAPP_UUID) {

      @Override
      public void receiveData(Context context, UUID logUuid, Long timestamp, Long tag, int data) {
        // Check this is the compass headings log
        if(tag.intValue() == DATA_LOG_TAG_COMPASS) {
          // Get the compass value and append to result StringBuilder
          resultBuilder.append("Heading: " + data + " degrees");
          resultBuilder.append("\n");
        }
      }

      @Override
      public void onFinishSession(Context context, UUID logUuid, Long timestamp, Long tag) {
        super.onFinishSession(context, logUuid, timestamp, tag);

        // Display all compass headings received
        textView.setText("Session finished!\n" + "Results were: \n\n" + resultBuilder.toString());
      }

    };

    // Register DataLogging Receiver
    PebbleKit.registerDataLogReceiver(this, dataloggingReceiver);
  }

  @Override
  protected void onPause() {
    super.onPause();

    // Always unregister callbacks
    if(dataloggingReceiver != null) {
      unregisterReceiver(dataloggingReceiver);
    }
  }
}package com.getpebble.dataloggingtest;

import android.app.Activity;
import android.content.Context;
import android.os.Bundle;
import android.widget.TextView;

import com.getpebble.android.kit.PebbleKit;
import com.getpebble.android.kit.PebbleKit.PebbleDataLogReceiver;

import java.util.UUID;

/**
 * MainActivity class
 * Implements a PebbleDataLogReceiver to process received log data, 
 * as well as a finished session.
 */
public class MainActivity extends Activity {

  // Configuration
  private static final UUID WATCHAPP_UUID = UUID.fromString("12258306-6cff-4b67-8af3-6f14105e8d8f");
  private static final int DATA_LOG_TAG_COMPASS = 52;

  // App elements
  private PebbleDataLogReceiver dataloggingReceiver;
  private TextView textView;
  private StringBuilder resultBuilder = new StringBuilder();

  @Override
  protected void onCreate(Bundle savedInstanceState) {
    super.onCreate(savedInstanceState);
    setContentView(R.layout.activity_main);

    // Setup TextView
    textView = (TextView)findViewById(R.id.text_view);
    textView.setText("Waiting for logging data...");
  }

  @Override
  protected void onResume() {
    super.onResume();

    // Define data reception behavior
    PebbleDataLogReceiver dataloggingReceiver = new PebbleDataLogReceiver(WATCHAPP_UUID) {

      @Override
      public void receiveData(Context context, UUID logUuid, Long timestamp, Long tag, int data) {
        // Check this is the compass headings log
        if(tag.intValue() == DATA_LOG_TAG_COMPASS) {
          // Get the compass value and append to result StringBuilder
          resultBuilder.append("Heading: " + data + " degrees");
          resultBuilder.append("\n");
        }
      }

      @Override
      public void onFinishSession(Context context, UUID logUuid, Long timestamp, Long tag) {
        super.onFinishSession(context, logUuid, timestamp, tag);

        // Display all compass headings received
        textView.setText("Session finished!\n" + "Results were: \n\n" + resultBuilder.toString());
      }

    };

    // Register DataLogging Receiver
    PebbleKit.registerDataLogReceiver(this, dataloggingReceiver);
  }

  @Override
  protected void onPause() {
    super.onPause();

    // Always unregister callbacks
    if(dataloggingReceiver != null) {
      unregisterReceiver(dataloggingReceiver);
    }
  }
}