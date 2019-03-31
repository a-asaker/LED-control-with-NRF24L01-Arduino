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
  pinMode(3, OUTPUT);// led
  pinMode(2, INPUT);// push button
  digitalWrite(2,HIGH);// pull-up resistor Through software
  radio.begin();
  radio.openWritingPipe(addresses[0]);
  radio.openReadingPipe(1, addresses[1]); // 00002
  radio.setPALevel(RF24_PA_LOW);
}

void loop() {
  radio.stopListening();//start working as a sender
  delay(5);
  st = digitalRead(2);
  radio.write(&st, sizeof(st));//send
  delay(5);
  radio.startListening();//start working as a receiver
  while (!radio.available());
  radio.read(&rcv, sizeof(rcv));//receive
  digitalWrite(3, !(int)rcv);// it's pulled up --> so it reads 1 as 0 vice versa
}
