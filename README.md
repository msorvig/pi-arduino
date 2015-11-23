Programming the Arduino Mega from the Raspberry Pi.

Using the following software:

- the Arduino SDK (headers, sources, but not the IDE)
- avrdude for programming the Arduino
- Gcc AVR cross-compiler

1) Install needed prerequisites

    sudo apt-get install arduino-core avrdude gcc-avr binutils-avr gdb-avr avr-libc

2) Compile the Ardunio Mega archive/library

    cd archive
    make

This will crate libarduinomega.a

3) Compile and run the blink example

    cd blink-arduino
    make
    sudo make up
    sudo make screen (Ctrl A-D to exit)

Done!

Implementation notes:

- Use C++, not C (.cpp files)

