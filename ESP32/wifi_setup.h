// Home WiFi Settings
const char* home_ssid = "I believe Wi can Fi";
const char* home_password = "Jirachi666";

void connectToHomeWiFi() {
  Serial.println("Connecting to Home WiFi...");
  WiFi.begin(home_ssid, home_password);
  Serial.println("Connected to Home WiFi");
}