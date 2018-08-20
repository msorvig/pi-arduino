# Setup for Arduino Nano (clone), which based on atmega328p and is similar (in capabilites) to the standard UNO.
MCU=atmega328p
VARIANT=standard

PATH_ROOT=/usr/share/arduino/hardware/arduino
PATH_CORE=${PATH_ROOT}/cores/arduino
PATH_VARIANT=${PATH_ROOT}/variants/${VARIANT}

F_CPU=16000000
FLAGS=-mmcu=${MCU} -Os -I${PATH_CORE} -I${PATH_VARIANT} -DF_CPU=${F_CPU}

OBJECT_FILES=WInterrupts.o wiring.o wiring_digital.o wiring_analog.o wiring_pulse.o wiring_shift.o CDC.o HID.o HardwareSerial.o IPAddress.o Print.o Stream.o Tone.o USBCore.o WMath.o WString.o main.o new.o

%.o: ${PATH_CORE}/%.c
	avr-gcc -o $@ -c $^ ${FLAGS}
%.o: ${PATH_CORE}/%.cpp
	avr-gcc -o $@ -c $^ ${FLAGS}

archive: ${OBJECT_FILES}
	ar cr libarduino${VARIANT}.a ${OBJECT_FILES}
clean:
	rm -f libarduino${VARIANT}.a ${OBJECT_FILES} 
