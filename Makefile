BIN = electric_bell
OBJS = main.o InterruptHandler.o BellDriver.o
MCU_TARGET = attiny85

CC = avr-gcc
CXX = ${CC}
OBJCOPY=avr-objcopy
CFLAGS= -Wall -Os -DF_CPU=1000000 -mmcu=${MCU_TARGET}
CXXFLAGS = ${CFLAGS}

.PHONY : install clean erase fuse_read fuse_write

${BIN}.hex: ${BIN}.elf
	${OBJCOPY} -j .text -j .data -O ihex $< $@
	avr-size --format=avr --mcu=${MCU_TARGET} $<

${BIN}.elf: ${OBJS}
	${CC} ${CFLAGS} -o $@ $^

install: ${BIN}.hex
	avrdude -c usbasp -p t85 -U flash:w:$<:i

clean:
	rm -f ${BIN}.elf ${BIN}.hex ${OBJS}

fuse_read:
	avrdude -c usbasp -p t85 -U lfuse:r:lfuse_val.hex:h -U hfuse:r:hfuse_val.hex:h

fuse_write:
	avrdude -c usbasp -p t85 -U lfuse:w:lfuse_val.hex:m -U hfuse:w:hfuse_val.hex:m

erase:
	avrdude -c usbasp -p t85 -e

all: ${BIN}.elf
