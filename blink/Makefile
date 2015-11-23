# arduino include paths for heaaders
A_ROOT=/usr/share/arduino/hardware/arduino
A_CORE=${A_ROOT}/cores/arduino
A_MEGA=${A_ROOT}/variants/mega

all: link

# compile the 'blink' application
blink.o: blink.cpp
	avr-gcc -mmcu=atmega1280 -Os -I${A_CORE} -I${A_MEGA} -c blink.cpp

# link the application with the arduino archive; create '.hex' file for flashing
link: blink.o
	avr-gcc -mmcu=atmega1280 -Os blink.o ../archive/libarduinomega.a -o prog.o
	avr-objcopy -j .text -j .data -O ihex prog.o blink.hex

# flash the arudino
up:
	sudo avrdude -F -V -c stk500v2 -p ATMEGA2560 -P /dev/ttyACM0 -b 115200 -U flash:w:blink.hex

screen:
	screen /dev/ttyACM0 -b 115200

clean:
	rm blink.o prog.o blink.hex

# attempt serial reset
magic:
	sudo avrdude -c arduino -P /dev/ttyACM0 -p atmega328p -U hfuse:r:-:h