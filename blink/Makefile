A_ROOT=/usr/share/arduino/hardware/arduino
A_CORE=${A_ROOT}/cores/arduino
A_MEGA=${A_ROOT}/variants/mega

F_CPU=16000000
MCU=atmega1280

all: link

blink.o: blink.cpp
	avr-gcc -mmcu=atmega1280 -Os -I${A_CORE} -I${A_MEGA} -c blink.cpp

link: blink.o
	avr-gcc -mmcu=atmega1280 -Os -I${A_CORE} -I${A_MEGA} blink.o ../archive/libarduinomega.a -o prog.o
	avr-objcopy -j .text -j .data -O ihex prog.o blink.hex

up:
	avrdude -F -V -c stk500v2 -p ATMEGA2560 -P /dev/ttyACM0 -b 115200 -U flash:w:blink.hex

screen:
	screen /dev/ttyACM0 -b 115200

clean:
	rm main.o wiring_digital.o wiring.o blink.o prog.o blink.hex
	
magic:
	avrdude -c arduino -P /dev/ttyACM0 -p atmega328p -U hfuse:r:-:h
	
	
	

