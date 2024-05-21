#include <Arduino.h>
#include <Elog.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>

#include <ElegantOTA.h>

Elog elog;
const char* ssid = "FREE";
const char* password = "gratisgratis";


WebServer server(80);

// put function declarations here:
int myFunction(int, int);

void setup() {
  // put your setup code here, to run once:
    Serial.begin(115200);
    elog.addSerialLogging(Serial, "Main", DEBUG);
    elog.log(ALERT, "Progtama arrancado");
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);
    int result = myFunction(2, 3);

    while (WiFi.status() != WL_CONNECTED) {
       delay(500);
       elog.log(ALERT, "Esperando WIFI");
    }

  server.on("/", []() {
    server.send(200, "text/plain", "Hi! This is ElegantOTA Demo.");
  });

  ElegantOTA.begin(&server); 

  server.begin();

}

void loop() {
   ElegantOTA.loop();
  // put your main code here, to run repeatedly:

      for (uint16_t counter = 0; counter < 1000; counter++) {
        elog.log(INFO, "Nuestro contador es %d", counter);
        if (counter == 3) { // Normally we dont have time from the very beginning. This simulates behaveour
            // We come up with 15th of july 2023 at 08:12:34
            // But find the time in your own way. There are many
            elog.log(NOTICE, "Ahora damos el tiempo real");
            Elog::provideTime(2023, 7, 15, 8, 12, 34);
        }
        delay(1007);
    }
}

// aqui ponemos cosas nuevas:
int myFunction(int equis, int y) {
  return equis + y;
}