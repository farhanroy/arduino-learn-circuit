//
// Copyright 2015 Google Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

// FirebaseDemo_ESP8266 is a sample that demo the different functions
// of the FirebaseArduino API.

#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

// Set these to run example.
#define FIREBASE_HOST "royma-b2552.firebaseio.com"
#define FIREBASE_AUTH "PMc8Z6UhcJE2dpwC5WvJ2QLThuQU4tjKZqSk06NQ"
#define WIFI_SSID "roy14"
#define WIFI_PASSWORD "wennnak123"

void setup() {
  Serial.begin(9600);

  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  digitalWrite(LED_BUILTIN, LOW); 
}

int n = 0;

void loop() {
 
  if (Firebase.failed()) {
      Serial.print("setting /number failed:");
      Serial.println(Firebase.error());  
      return;
  }
  if(Firebase.getInt("tombol") == 1){
    Serial.println("hidup");   
    digitalWrite(LED_BUILTIN, HIGH); 
    }else if(Firebase.getInt("tombol") == 0){
      Serial.println("mati"); 
      digitalWrite(LED_BUILTIN, LOW);
      }
      delay(500);
 
}
