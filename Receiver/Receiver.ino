/*
Coded By : A_Asaker
NRF:-V+ -> Arduino(3.3V) ***IMPORTANT***
    -GND-> Arduino(GND)
    -CSN-> Arduino(8)
    -CE -> Arduino(7)
    -MOSI->Arduino(11)
    -MISO->Arduino(12)
    -SCK-> Arduino(13)

led -> arduino(3)
push button -> arduino(2)
 */
 
#include <RF24.h>
#include <nRF24L01.h>
#include <SPI.h>

const byte addresses[][6] = {"00001", "00002"};
RF24 radio(7, 8); // CE, CSN
int st, rcv;
void setup() {
  pinMode(3, OUTPUT);
  pinMode(2, INPUT);
  digitalWrite(2,HIGH);// pull-up resistor through code
  radio.begin();
  radio.openWritingPipe(addresses[1]);
  radio.openReadingPipe(1, addresses[0]); // 00002
  radio.setPALevel(RF24_PA_LOW);
}

void loop() {
  delay(5);
  radio.startListening();//start working as a receiver
  if (radio.available()) {
    while (radio.available()) {
      radio.read(&rcv, sizeof(st));//receive
      digitalWrite(3, !(int)rcv);// it's pulled up --> so it reads 1 as 0 vice versa
    }
  }
  delay(5);
  radio.stopListening();//start working as a sender
  st = digitalRead(2);
  radio.write(&st, sizeof(st));//send
}
