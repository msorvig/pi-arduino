PROGRAM=blink

# Setup for Arduino Nano (clone), which based on atmega328p and is similar (in capabilites) to the standard UNO.
MCU=atmega328p
VARIANT=standard

PATH_ROOT=/usr/share/arduino/hardware/arduino
PATH_CORE=${PATH_ROOT}/cores/arduino
PATH_VARIANT=${PATH_ROOT}/variants/${VARIANT}

F_CPU=16000000
FLAGS=-mmcu=${MCU} -Os -I${PATH_CORE} -I${PATH_VARIANT} -DF_CPU=${F_CPU}

# The aruduino should be conneted to one of the /dev/ttyUSBs. Use the first one.
PORT=$(shell ls /dev/ttyUSB* | head -1)

# baudrate, empirically determined
BAUDRATE=57600

%.o: %.c
	avr-gcc -o $@ -c $^ ${FLAGS}
%.o: %.cpp
	avr-gcc -o $@ -c $^ ${FLAGS}

all: link

# link the application with the arduino archive; create '.hex' file for flashing
link: blink.o
	avr-gcc -mmcu=${MCU} -Os ${PROGRAM}.o ../archive/libarduino${VARIANT}.a -o prog.o
	avr-objcopy -j .text -j .data -O ihex prog.o ${PROGRAM}.hex

# flash the arudino
up:
	sudo avrdude -c arduino -p ${MCU} -P ${PORT} -b ${BAUDRATE} -U flash:w:${PROGRAM}.hex

screen:
	screen ${PORT} -b 115200

clean:
	rm blink.o prog.o ${PROGRAM}.hex

# attempt serial reset
magic:
	sudo avrdude -c arduino -P ${PORT} -p ${MCU} -U hfuse:r:-:h