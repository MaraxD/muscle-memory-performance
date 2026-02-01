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

</ul>

## Prerequisites
1. Clone this repository and make sure you have **Arduino** and **MaxMSP 8** installed.
2. Clone https://github.com/lysdexic-audio/jweb-hands-landmarker and replace the file `jweb-hands-landmarker.maxpat` found in that repo with the one found in this repo.
3. Run the `readMacAddress()` function (found in both scripts `cod/cod.ino` and `ble_client/ble_client.ino`) to get the MAC address of each ESP, then assign the opposite values to `broadcastAddress` variable.


