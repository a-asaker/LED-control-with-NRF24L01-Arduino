# NRF24L01 Bidirectional LED Control :
Control 2 LEDs Connected To 2 Arduino Boards With 2 NRF24L01 Transceiver Modules.

Coded By : a-asaker.

# Components : 
        - 2X Arduino Boards.
        - 2X NRF24L01 Modules.
        - 2 Push-Buttons.
        - 2 LEDs.
        
# Hardware Connection : 
* Note : The Arduino Used Here Is Arduino Nano/Uno.
         
          Arduino | NRF24L01
          --------|---------
           3.3v   |   V+
            GND   |   GND 
             8    |   CSN
             7    |   CE
       (MOSI)11   |   MOSI
       (MISO)12   |   MISO
        (SCK)13   |   SCK
           -----------------
        LED => (+) | Arduino(3)
               (-) | Arduino(GND)
        Push-Button => Pin | 5v
                       Pin | Arduino(2)
                          
* Note : The Same Connection For Both Arduino Boards.

You Should Install Libs `RF24.h` And `nRF24L01.h` For Arduino IDE.
