#include <stdint.h>

#define MY_PORT_B *(unsigned char*)0x25
#define MY_PORT_B_DDR *(unsigned char*)0x24
#define DDRD *(unsigned char*)0x2A
#define PORTD *(unsigned char*)0x2B
#define GREEN1 0x02
#define YELLOW1 0x03
#define RED1 0x04
#define GREEN2 0x05
#define YELLOW2 0x06
#define RED2 0x07
#define OFF 0x00

// Check godbolt.org for at se om koden er ok ift. AVR gcc 14.2.0
// https://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-7810-Automotive-Microcontrollers-ATmega328P_Datasheet.pdf
// Guess binary number game? 8 lights..

void setup();
void loop();
void allOff();

int main() {
  setup();
}

void setup() {
  // put your setup code here, to run once:¨
  //pinMode(LED_BUILTIN, OUTPUT);

  int i = 0;
  volatile long pause = 0;

  for (i = 2; i < 8; i++) {
      DDRD |= (1 << i);
      PORTD |= (1 << i);
  }

  for (pause=0; pause < 100000; pause++) {
    pause = pause;
  }

  allOff();

  while (1) {
    loop();
  }

}

void loop() {
  PORTD |= (1 << RED1);
  PORTD |= (1 << GREEN2);


  volatile long pause = 0;
  for (pause=0; pause < 1000000; pause++) {
    pause = pause;
  }
  
  PORTD &= ~(1 << GREEN2);
  PORTD |= (1 << YELLOW2);
  for (pause=0; pause < 1000000; pause++) {
    pause = pause;
  }
  // Bitwise OR operator to turn on the light
  PORTD &= ~(1 << YELLOW2);
  PORTD |= (1 << YELLOW1);
  PORTD |= (1 << RED2);
  

  for (pause=0; pause < 1000000; pause++) {
    pause = pause;
  }

  // Bitwise AND operator to turn off the light
  PORTD &= ~(1 << RED1);
  PORTD &= ~(1 << YELLOW1);
  PORTD |= (1 << GREEN1);

  for (pause=0; pause < 1000000; pause++) {
    pause = pause;
  }

  PORTD &= ~(1 << GREEN1);
  PORTD |= (1 << YELLOW1);

for (pause=0; pause < 1000000; pause++) {
    pause = pause;
  }
  PORTD &= ~(1 << YELLOW1);
  PORTD |= (1 << YELLOW2);
  PORTD |= (1 << RED1);

  for (pause=0; pause < 1000000; pause++) {
    pause = pause;
  }
  PORTD &= ~(1 << RED2);
  PORTD &= ~(1 << YELLOW2);
}

void allOff() {
  PORTD = OFF;
  // DDRD = OFF;
}