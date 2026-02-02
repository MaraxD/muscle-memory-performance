# Muscle Memory

## About
An interactive performance that explores the mourning of one’s past and the person they could have become. This one-woman show functions as an open diary, the performer navigating through its path using their muscles, only to discover they cannot change the past. They are, ultimately, a watcher in their own story.

## Materials used
<ul>
  <li>
    ESP32-S3-WROOM-1 (ESP32S3 Dev Module - arduino board)
  </li>
  <li>
    ESP-32 (NodeMCU-32S - arduino board)
  </li>
  <li>
    Smart watch with a heartbeat sensor (I used a Garmin Instict 2 Solar watch)
  </li>
  <li>
    MyoWare muscle sensor
  </li>
</ul>

## Prerequisites
1. Clone this repository and make sure you have **Arduino** and **MaxMSP 8** installed.
2. Clone https://github.com/lysdexic-audio/jweb-hands-landmarker and replace the file `jweb-hands-landmarker.maxpat` found in that repo with the one found in this repo.
3. Run the `readMacAddress()` function (found in both scripts `cod/cod.ino` and `ble_client/ble_client.ino`) to get the MAC address of each ESP, then assign the opposite values to `broadcastAddress` variable.

## Wiring up the muscle sensor (EMG) to the main ESP32 board
EMG | ESP32                 | Info | 
--- |-----------------------| --- 
- | 3.3V                  | Power
+ | GND                   | Ground 
SIG | 4 (or any analog pin) | Signal

## Broadcasting heartbeat data to ESP
Make sure your smartwatch has a heartbeat sensor and can also _broadcast data_. BLE devices with a heart rate monitor usually have the service UUID set to `180D` (heart rate service) and the client UUID to `2A37` (heart rate measurement characteristic), but if that's not the case you can verify the UUIDs using nRF Connect and modify tha values inside `ble_client/ble_client.ino`.
<br>

If everything is set up correctly it's time to broadcast the data. On my Garmin watch, in order to do that, I had to: hold the 'up' key -> sensors & accesories -> wrist heart rate -> broadcast heart rate. The watch should automatically connect to the ESP.
<br>

**If the ESP does not find the smartwatch, try disconnecting it completely from your phone and turn off the bluetooth and try again.**

