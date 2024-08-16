CC = gcc
AS = nasm
LD = ld

# Cross-compiler settings
TARGET = i386-elf
CFLAGS = -ffreestanding -m32 -Wall -nostdlib -nostartfiles
LDFLAGS = -ffreestanding -m32

# Files
SOURCES = $(wildcard *.c) $(wildcard drivers/*.c) $(wildcard FileSys/*.c) $(wildcard intHandle/*.c) $(wildcard MemMan/*.c) $(wildcard ProccMan/*.c) $(wildcard syscalls/*.c)
OBJECTS = $(SOURCES:.c=.o)
ASSEMBLY = $(wildcard *.asm) $(wildcard drivers/*.asm) $(wildcard intHandle/*.asm) $(wildcard ProccMan/*.asm) $(wildcard syscalls/*.asm)
BIN = os_image.bin

# Default target
all: $(BIN)

# Compile assembly files
%.o: %.asm
	$(AS) -f elf $< -o $@

# Compile C files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Link everything
$(BIN): $(OBJECTS)
	$(LD) $(LDFLAGS) -o $(BIN) $(OBJECTS) -T linker.ld

# Clean up
clean:
	rm -f *.o $(BIN)