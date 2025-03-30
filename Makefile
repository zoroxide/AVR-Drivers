MCU = atmega32
CC = avr-gcc
OBJCOPY = avr-objcopy
CFLAGS = -mmcu=$(MCU) -Wall -Os
TARGET = hydra

SRCDIR = hydra
SRC = $(wildcard $(SRCDIR)/**/*.c) main.c
OBJ = $(SRC:.c=.o)

all: $(TARGET).hex

$(TARGET).elf: $(SRC)
	$(CC) $(CFLAGS) -o $@ $^

$(TARGET).hex: $(TARGET).elf
	$(OBJCOPY) -O ihex $< $@

flash: $(TARGET).hex
	avrdude -c usbasp -p $(MCU) -U flash:w:$(TARGET).hex:i

clean:
	rm -f $(TARGET).elf $(TARGET).hex $(OBJ)
