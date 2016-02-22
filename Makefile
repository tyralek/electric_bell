BIN = electric_bell
OBJS = main.o
MCU_TARGET = attiny13

CC = avr-gcc
OBJCOPY=avr-objcopy
CFLAGS= -Wall -Os -DF_CPU=9600000 -mmcu=${MCU_TARGET}

.PHONY : install clean

${BIN}.hex: ${BIN}.elf
	${OBJCOPY} -j .text -j .data -O ihex $< $@
	avr-size --format=avr --mcu=${MCU_TARGET} $<

${BIN}.elf: ${OBJS}
	${CC} -o $@ $^

install: ${BIN}.hex
	avrdude -c usbasp -p t13 -U flash:w:$<:i

clean:
	rm -f ${BIN}.elf ${BIN}.hex ${OBJS}
