#include <WiFi.h>
#include <esp_wifi.h>
#include <esp_now.h>

// mac addres of the esp on the performer
uint8_t broadcastAddress[] = {0xD8, 0x3B, 0xDA, 0x99, 0x61, 0xAC};

// Create a struct_message to hold incoming sensor readings
typedef struct struct_message {
  int heartbeat;
  int muscleTension;
} struct_message;

struct_message incomingReadings;
int heartbeat=0, muscleTension=0;

esp_now_peer_info_t peerInfo;

// Callback when data is received
void OnDataRecv(const esp_now_recv_info_t *recv_info, const uint8_t *incomingData, int len) {
  memcpy(&incomingReadings, incomingData, sizeof(incomingReadings));
  heartbeat = incomingReadings.heartbeat;
  muscleTension=incomingReadings.muscleTension;
}

void readMacAddress() {
  uint8_t baseMac[6];
  esp_err_t ret = esp_wifi_get_mac(WIFI_IF_STA, baseMac);
  if (ret == ESP_OK) {
    Serial.printf("%02x:%02x:%02x:%02x:%02x:%02x\n",
                  baseMac[0], baseMac[1], baseMac[2],
                  baseMac[3], baseMac[4], baseMac[5]);
  } else {
    Serial.println("Failed to read MAC address");
  }
}

void setup(){
  Serial.begin(115200);  

  // !! only to be executed in the beginning, when new boards are connected !!
  // WiFi.mode(WIFI_STA);
  // WiFi.STA.begin();

  // Serial.print("[DEFAULT] ESP32 Board MAC Address: ");
  // readMacAddress();

  // Set device as a Wi-Fi Station
  WiFi.mode(WIFI_STA);
  // Init ESP-NOW
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  // Register peer
  memcpy(peerInfo.peer_addr, broadcastAddress, 6);
  peerInfo.channel = 0;
  peerInfo.encrypt = false;

  // Add peer
  if (esp_now_add_peer(&peerInfo) != ESP_OK) {
    Serial.println("Failed to add peer");
    return;
  }
  // Register for a callback function that will be called when data is received
  esp_now_register_recv_cb(esp_now_recv_cb_t(OnDataRecv));
}

void loop(){
  // Serial.print(heartbeat);

  // Serial.print(" ");
  Serial.println(muscleTension);

  delay(1000);
}





