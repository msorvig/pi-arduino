# arduino include paths for heaaders
A_ROOT=/usr/share/arduino/hardware/arduino
A_CORE=${A_ROOT}/cores/arduino
A_MEGA=${A_ROOT}/variants/mega

all: link

# compile the 'serial' application
serial.o: serial.cpp
	avr-gcc -mmcu=atmega1280 -Os -I${A_CORE} -I${A_MEGA} -c serial.cpp

# link the application with the arduino archive; create '.hex' file for flashing
link: serial.o
	avr-gcc -mmcu=atmega1280 -Os serial.o ../archive/libarduinomega.a -o prog.o
	avr-objcopy -j .text -j .data -O ihex prog.o serial.hex

# flash the arudino
up:
	sudo avrdude -F -V -c stk500v2 -p ATMEGA2560 -P /dev/ttyACM0 -b 115200 -U flash:w:serial.hex

screen:
	sudo screen /dev/ttyACM0 -b 9600

clean:
	rm serial.o prog.o serial.hex
