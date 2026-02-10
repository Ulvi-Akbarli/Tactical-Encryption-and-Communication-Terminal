#include <WiFi.h>
#include <PubSubClient.h>
#include <LiquidCrystal_I2C.h>


const char* ssid = "Wokwi-GUEST";
const char* password = "";
const char* mqtt_server = "broker.hivemq.com";
const char* topic = "milli_mudafie/terminal_001";
const char* key = "AZ-DEF-2025"; // Şifrə açarı

const int redPin = 14;
const int greenPin = 12;
const int bluePin = 27;

LiquidCrystal_I2C lcd(0x27, 16, 2);
WiFiClient espClient;
PubSubClient client(espClient);

void setup() {

  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  setColor(255, 255, 0);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Sistem Acilir...");

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) { delay(500); }
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
  
}

void callback(char* topic, byte* payload, unsigned int length) {
  String encryptedHex = "";
  char decrypted[length + 1];

  for (int i = 0; i < length; i++) {
    
    if (payload[i] < 0x10) encryptedHex += "0";
    encryptedHex += String(payload[i], HEX);
    
    // Deşifrə (XOR)
    decrypted[i] = (char)(payload[i] ^ key[i % strlen(key)]);
  }
  decrypted[length] = '\0';

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Enc:"); 
  lcd.print(encryptedHex.substring(0, 12)); 
  
  lcd.setCursor(0, 1);
  lcd.print("Dec:");
  lcd.print(decrypted);

 String checkMsg = String(decrypted);  
 checkMsg.toUpperCase();

if (checkMsg == "ATTACK") {
    setColor(0, 255, 0); 
} 
else if (checkMsg == "STOP") {
    setColor(255, 0, 0); 
} 
else {
    setColor(255, 255, 0); 
}
}

void setColor(int red, int green, int blue) {
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}

void loop() {
  if (!client.connected()) {
    while (!client.connected()) {
      if (client.connect("ESP32_Device")) {
        client.subscribe(topic);
      } else { delay(5000); }
    }
  }
  client.loop();
}