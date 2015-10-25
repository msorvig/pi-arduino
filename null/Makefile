A_ROOT=/usr/share/arduino/hardware/arduino
A_CORE=${A_ROOT}/cores/arduino
A_MEGA=${A_ROOT}/variants/mega

F_CPU=16000000
MCU=atmega1280

all: link

null.o: null.cpp
	avr-gcc -mmcu=atmega1280 -Os -I${A_CORE} -I${A_MEGA} -c null.cpp

link: null.o
	avr-gcc -mmcu=atmega1280 -Os -I${A_CORE} -I${A_MEGA} null.o ../archive/libarduinomega.a -o prog.o
	avr-objcopy -j .text -j .data -O ihex prog.o null.hex

up:
	avrdude -F -V -c stk500v2 -p ATMEGA2560 -P /dev/ttyACM0 -b 115200 -U flash:w:null.hex

screen:
	screen /dev/ttyACM0 -b 115200

clean:
	rm main.o wiring_digital.o wiring.o null.o prog.o null.hex
	
magic:
	avrdude -c arduino -P /dev/ttyACM0 -p atmega328p -U hfuse:r:-:h
	
	
	

