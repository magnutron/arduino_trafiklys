# Compile with avr-GCC
CC=avr-GCC
CFLAGS = -mmcu=avr5 -Os
# Copy with avr-objcopy
OBJCPY = avr-objcopy
CPYFLAGS = -O ihex -R .eeprom
# Upload with avrdude
AVRD = avrdude
AVRD_PROGRAMMER = -c arduino
AVRD_MCU = -p m328p
AVRD_BAUD = -b 115200
AVRD_PORT = -P COM3
AVRD_UPLOAD = -U flash:w:trafiklys.hex:i
AVRDFLAGS = $(AVRD_PROGRAMMER) $(AVRD_MCU) $(AVRD_BAUD) $(AVRD_PORT) -D $(AVRD_UPLOAD)


all: compile hex upload

compile:
	$(CC) $(CFLAGS) -o trafiklys.o trafiklys.c

hex:
	$(OBJCPY) $(CPYFLAGS) trafiklys.o trafiklys.hex

upload:
	$(AVRD) $(AVRDFLAGS)

clean:
	rm -f *.o