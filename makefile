# Compiler and Tools
CC = gcc
AS = nasm
LD = ld
OBJCOPY = objcopy
CXX = g++
CFLAGS = -ffreestanding -m32 -nostdlib -nostartfiles -fno-exceptions -fno-rtti
LDFLAGS = -T linker.ld -nostdlib -nostartfiles -m32
ASFLAGS = -f bin
OBJDIR = obj
BINDIR = bin
SRC = $(wildcard Kernel/**/*.c) $(wildcard GUI/**/*.c) $(wildcard HAL/**/*.c) \
      $(wildcard lib/**/*.c) $(wildcard NtwrkLayer/**/*.c) $(wildcard pkgman/**/*.c) \
      $(wildcard SCL/**/*.c) $(wildcard sec/**/*.c) $(wildcard Shell/**/*.c) \
      $(wildcard SM-DT/**/*.c) $(wildcard UserAuth/**/*.c) $(wildcard Virt/**/*.c) \
      $(wildcard VMM/**/*.c) $(wildcard AdvSM/**/*.c)
OBJ = $(SRC:%.c=$(OBJDIR)/%.o)

# Targets
all: os-image

os-image: kernel.bin
	@echo "Creating OS image..."
	cat bootloader.bin kernel.bin > $(BINDIR)/os-image.iso

kernel.bin: $(OBJ)
	@mkdir -p $(OBJDIR)
	$(LD) $(LDFLAGS) -o kernel.elf $(OBJ)
	$(OBJCOPY) -O binary kernel.elf kernel.bin

$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Cleaning up..."
	rm -rf $(OBJDIR) kernel.elf kernel.bin $(BINDIR)/os-image.iso

.PHONY: all clean
