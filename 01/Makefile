SRC := main.c
EXE := main.exe
BIR := main.bir
DASM := main.dasm

FUNC := foo
QEMU_RUNNER := qemu-arm #qemu-arm-static

.PHONY: all clean run

all: clean build bir dasm

build:
	$(MAKE) $(EXE)

$(EXE): $(SRC)
	arm-linux-gnueabi-gcc -marm -g -o $@ $< 

clean:
	rm -f $(EXE)

run: $(EXE)
	-QEMU_LD_PREFIX=/usr/arm-linux-gnueabi $(QEMU_RUNNER) $(EXE)

bir: $(EXE)
	bap $(EXE) -d --print-symbol=$(FUNC) > $(BIR)

dasm: $(EXE)
	arm-linux-gnueabi-objdump -DSshg $(EXE) > $(DASM)

