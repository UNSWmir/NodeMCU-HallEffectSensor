#include <readiness_io.h>
#include "config.h"

const int       LED_PIN        = 4;     // The pin connecting the LED (D3)
const int       INTERRUPT_PIN  = 14;    // The pin connect the test button (D5)

volatile byte interrupt = 0;
static unsigned long last_interrupt_time = 0;

readiness_io client(CHANNEL_ID, TOPIC, SENSOR_ID, VERSION, FORMAT);

/* Interrupt for assessing a change in the hall effect sensor (both high and low) */
void halleffectInterrupt() {
  unsigned long interrupt_time = millis();
 if (interrupt_time - last_interrupt_time > DEBOUNCE_TIME)
  {
   interrupt++;
  }
 last_interrupt_time = interrupt_time;
}


void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUILTIN_LED, OUTPUT);
  digitalWrite(BUILTIN_LED, HIGH); // internal LED is switched on when low - so we have to switch it off/

  Serial.begin(115200);
  Serial.setTimeout(2000);
  while(!Serial) { } // Wait for serial to initialize.

  Serial.println("Device Started");

  Serial.print("Connecting to ");
  Serial.println(WIFI_SSID);
  client.wifiConnection(WIFI_SSID, WIFI_PASS);

  pinMode(INTERRUPT_PIN, INPUT_PULLUP); // Set the interrupt pin for the reed/hall effect
  attachInterrupt(digitalPinToInterrupt(INTERRUPT_PIN), halleffectInterrupt, CHANGE);  // Attach the interrupt.

  client.testConnection();
}


void loop() {
  if(interrupt>0){
    interrupt=0;

    // GATE_STATE 0=open 1= closed
    bool GATE_STATE = !digitalRead(INTERRUPT_PIN);
    digitalWrite(LED_PIN,GATE_STATE);
    client.publishData(GATE_STATE);

  }
}
