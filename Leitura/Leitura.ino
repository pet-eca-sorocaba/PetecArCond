#include <IRremote.h>

#define RECV_PIN 8

IRrecv irrecv(RECV_PIN);
decode_results results;

IRsend irsend;

void ircode   (decode_results *results);
void encoding (decode_results *results);
void dumpInfo (decode_results *results);
void dumpRaw  (decode_results *results);
void dumpCode (decode_results *results);


void setup()
{
  Serial.begin(9600);
  Serial.println("Enabling IRin");

  irrecv.enableIRIn(); // Start the receiver
  Serial.println("Enabled IRin");

}
void loop() {
 
  if (irrecv.decode(&results))
  {

      Serial.println("Botao1");
     
      ircode(&results);
      encoding(&results);
      dumpInfo(&results);
      dumpRaw(&results);
      dumpCode(&results);
      irrecv.resume(); // Receive the next value

    Serial.print("\n\n\n");
  }

}

