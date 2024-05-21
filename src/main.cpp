#include <Arduino.h>
#include <Elog.h>

Elog elog;

// put function declarations here:
int myFunction(int, int);

void setup() {
  // put your setup code here, to run once:
    Serial.begin(115200);
    elog.addSerialLogging(Serial, "Main", DEBUG);
    elog.log(ALERT, "Sketch started");
    int result = myFunction(2, 3);
}

void loop() {
  // put your main code here, to run repeatedly:

      for (uint16_t counter = 0; counter < 1000; counter++) {
        elog.log(INFO, "Our counter is %d", counter);
        if (counter == 3) { // Normally we dont have time from the very beginning. This simulates behaveour
            // We come up with 15th of july 2023 at 08:12:34
            // But find the time in your own way. There are many
            elog.log(NOTICE, "Now we provide some real human time");
            Elog::provideTime(2023, 7, 15, 8, 12, 34);
        }
        delay(1007);
    }
}

// put function definitions here:
int myFunction(int equis, int y) {
  return equis + y;
}