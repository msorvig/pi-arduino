A_ROOT=/usr/share/arduino/hardware/arduino
A_CORE=${A_ROOT}/cores/arduino
A_MEGA=${A_ROOT}/variants/mega
A_AVR=/usr/lib/avr/include

F_CPU=16000000
MCU=atmega1280

all: archive

WInterrupts.o: ${A_CORE}/WInterrupts.c
	avr-gcc -mmcu=${MCU} -Os -I${A_CORE} -I${A_MEGA} -DF_CPU=${F_CPU} -c ${A_CORE}/WInterrupts.c
wiring.o: ${A_CORE}/wiring.c
	avr-gcc -mmcu=${MCU} -Os -I${A_CORE} -I${A_MEGA} -DF_CPU=${F_CPU} -c ${A_CORE}/wiring.c
wiring_digital.o: ${A_CORE}/wiring_digital.c
	avr-gcc -mmcu=${MCU} -Os -I${A_CORE} -I${A_MEGA} -DF_CPU=${F_CPU} -c ${A_CORE}/wiring_digital.c
wiring_analog.o: ${A_CORE}/wiring_analog.c
	avr-gcc -mmcu=${MCU} -Os -I${A_CORE} -I${A_MEGA} -DF_CPU=${F_CPU} -c ${A_CORE}/wiring_analog.c
wiring_pulse.o: ${A_CORE}/wiring_pulse.c
	avr-gcc -mmcu=${MCU} -Os -I${A_CORE} -I${A_MEGA} -DF_CPU=${F_CPU} -c ${A_CORE}/wiring_pulse.c
wiring_shift.o: ${A_CORE}/wiring_shift.c
	avr-gcc -mmcu=${MCU} -Os -I${A_CORE} -I${A_MEGA} -DF_CPU=${F_CPU} -c ${A_CORE}/wiring_shift.c
CDC.o: ${A_CORE}/CDC.cpp
	avr-g++ -mmcu=${MCU} -Os -I${A_CORE} -I${A_MEGA} -DF_CPU=${F_CPU} -c ${A_CORE}/CDC.cpp
HID.o: ${A_CORE}/HID.cpp
	avr-g++ -mmcu=${MCU} -Os -I${A_CORE} -I${A_MEGA} -DF_CPU=${F_CPU} -c ${A_CORE}/HID.cpp
HardwareSerial.o: ${A_CORE}/HardwareSerial.cpp
	avr-g++ -mmcu=${MCU} -Os -I${A_CORE} -I${A_MEGA} -DF_CPU=${F_CPU} -c ${A_CORE}/HardwareSerial.cpp
IPAddress.o: ${A_CORE}/IPAddress.cpp
	avr-g++ -mmcu=${MCU} -Os -I${A_CORE} -I${A_MEGA} -DF_CPU=${F_CPU} -c ${A_CORE}/IPAddress.cpp
Print.o: ${A_CORE}/Print.cpp
	avr-g++ -mmcu=${MCU} -Os -I${A_CORE} -I${A_MEGA} -DF_CPU=${F_CPU} -c ${A_CORE}/Print.cpp
Stream.o: ${A_CORE}/Stream.cpp
	avr-g++ -mmcu=${MCU} -Os -I${A_CORE} -I${A_MEGA} -DF_CPU=${F_CPU} -c ${A_CORE}/Stream.cpp
Tone.o: ${A_CORE}/Tone.cpp
	avr-g++ -mmcu=${MCU} -Os -I${A_CORE} -I${A_MEGA} -DF_CPU=${F_CPU} -c ${A_CORE}/Tone.cpp
USBCore.o: ${A_CORE}/USBCore.cpp
	avr-g++ -mmcu=${MCU} -Os -I${A_CORE} -I${A_MEGA} -DF_CPU=${F_CPU} -c ${A_CORE}/USBCore.cpp
WMath.o: ${A_CORE}/WMath.cpp
	avr-g++ -mmcu=${MCU} -Os -I${A_CORE} -I${A_MEGA} -DF_CPU=${F_CPU} -c ${A_CORE}/WMath.cpp
WString.o: ${A_CORE}/WString.cpp
	avr-g++ -mmcu=${MCU} -Os -I${A_CORE} -I${A_MEGA} -DF_CPU=${F_CPU} -c ${A_CORE}/WString.cpp
new.o: ${A_CORE}/new.cpp
	avr-g++ -mmcu=${MCU} -Os -I${A_CORE} -I${A_MEGA} -DF_CPU=${F_CPU} -c ${A_CORE}/new.cpp
main.o: ${A_CORE}/main.cpp
	avr-g++ -mmcu=${MCU} -Os -I${A_CORE} -I${A_MEGA} -DF_CPU=${F_CPU} -c ${A_CORE}/main.cpp	

OBJECT_FILES=WInterrupts.o wiring.o wiring_digital.o wiring_analog.o wiring_pulse.o wiring_shift.o CDC.o HID.o HardwareSerial.o IPAddress.o Print.o Stream.o Tone.o USBCore.o WMath.o WString.o main.o new.o

archive: ${OBJECT_FILES}
	ar cr libarduinomega.a ${OBJECT_FILES}

clean:
	rm -f libarduinomega.a ${OBJECT_FILES} 
