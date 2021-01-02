#include <ESP8266WiFi.h>                                                // esp8266 library
#include <FirebaseArduino.h>                                             // firebase library

#define FIREBASE_HOST "royma-b2552.firebaseio.com"                         // the project name address from firebase id
#define FIREBASE_AUTH "PMc8Z6UhcJE2dpwC5WvJ2QLThuQU4tjKZqSk06NQ"                    // the secret key generated from firebase
#define WIFI_SSID "g"                                          // input your home or public wifi name 
#define WIFI_PASSWORD "wennnak123"                                    //password of wifi ssid
                                                                // for external led
void setup() {
  Serial.begin(9600);
  delay(1000);
  pinMode(LED_BUILTIN, OUTPUT);      
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);                                      //try to connect with wifi
  Serial.print("Connecting to ");
  Serial.print(WIFI_SSID);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("Connected to ");
  Serial.println(WIFI_SSID);
  Serial.print("IP Address is : ");
  Serial.println(WiFi.localIP());                                                      //print local IP address
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);                                       // connect to firebase
  Firebase.setString("status", "l");  
  Serial.print(Firebase.getString("status"));
}

void loop() {
}
