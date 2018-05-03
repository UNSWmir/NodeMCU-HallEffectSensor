# NodeMCU-HallEffectSensor

NodeMCU with an AH180 Hall Effect Sensor transmitting data to the [readiness.io](https://readiness.io/) service

The Hall Effect Sensor that we've used essentially behaves like a switch. When a magnet is detected it closes the switch. So you can change the sensor to another switch, like a reed switch or push button and the code will continue to work.

This example is quite generic but the applications are quite wide.  Some include - checking a door/gate is open or closed, if the water level on a tank is low. You can even use it for things like Rain Gauges or Pulse Flow Meters

### Tutorial
We've put together a brief tutorial on [instructables](https://www.instructables.com/id/NodeMCU-Hall-Effect-Sensor/) for how to setup the device.

### Libaries

The arduino source code relies on the following libraries
* readiness.io (coming soon)
* [ticker](https://github.com/esp8266/Arduino/tree/master/libraries/Ticker)

### Basic Wiring Diagram
![Image or Wiring Diagram](https://github.com/UNSWmir/NodeMCU-HallEffectSensor/blob/master/GenericHallEffect_bb.png)
