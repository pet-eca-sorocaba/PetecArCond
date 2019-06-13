#include "DHT.h"
#include <IRremote.h>


#define pinoDHT A1

DHT dht(A1, DHT11);
IRsend irsend;

int khz = 38;

void setup() {
    Serial.begin(9600);
    Serial.println("Inicio do codigo teste");
    dht.begin();

    unsigned int irSignal[] = {};

    irsend.sendRaw(irSignal, sizeof(irSignal) / sizeof(irSignal[0]), khz);

    irSignal[] = {};

    irsend.sendRaw(irSignal, sizeof(irSignal) / sizeof(irSignal[0]), khz);
}

void loop() {
    float temperatura = dht.readTemperature();
    Serial.print("Temperatura: ");
    Serial.print(temperatura);
    Serial.println(" *C");
    delay(1000);

    if (temperatura < 27) {
        unsigned int irSignal[] = {};
        irsend.sendRaw(irSignal, sizeof(irSignal) / sizeof(irSignal[0]), khz);
    }
}
