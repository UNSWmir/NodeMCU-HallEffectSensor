//TODO:  Change to generic names before making public


const String    CHANNEL_ID    = "n5n09k7grwjf0zdc"; // The Readiness.io channel ID
const String    SENSOR_ID     = "switch_generic"; // Your AgriWebb or made up sensor ID
const String    TOPIC         = "water-level"; // The type of sensor or name of the data your sending
const String    VERSION       = "1";
const String    FORMAT        = "";

const char*     WIFI_SSID     = "FarmerNet"; // Your WiFi SSID / name
const char*     WIFI_PASS     = "SwitchNode37294"; // Your WiFi password

const uint8_t   TIMEZONE_OFFSET = 10; // The timezone the sensor is located in (eg. 10 for GMT)

const uint16_t  DEBOUNCE_TIME   = 200; // How long before the next gate reading can take place (ms)
