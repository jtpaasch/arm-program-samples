SRC := main.c

OPT_0 := -O0
EXE_0 := main.o0.exe
BIR_0 := main.o0.bir
DASM_0 := main.o0.dasm

OPT_1 := -O1
EXE_1 := main.o1.exe
BIR_1 := main.o1.bir
DASM_1 := main.o1.dasm

OPT_2 := -O2
EXE_2 := main.o2.exe
BIR_2 := main.o2.bir
DASM_2 := main.o2.dasm

OPT_3 := -O3
EXE_3 := main.o3.exe
BIR_3 := main.o3.bir
DASM_3 := main.o3.dasm

FUNC := dbl
QEMU_RUNNER := qemu-arm #qemu-arm-static

.PHONY: all clean run

all:
	$(MAKE) clean.o0 build.o0 bir.o0 dasm.o0
	$(MAKE) clean.o1 build.o1 bir.o1 dasm.o1
	$(MAKE) clean.o2 build.o2 bir.o2 dasm.o2
	$(MAKE) clean.o3 build.o3 bir.o3 dasm.o3

clean:
	$(MAKE) clean.o0
	$(MAKE) clean.o1
	$(MAKE) clean.o2
	$(MAKE) clean.o3

clean.o0:
	rm -f $(EXE_0)

clean.o1:
	rm -f $(EXE_1)

clean.o2:
	rm -f $(EXE_2)

clean.o3:
	rm -f $(EXE_3)

build:
	$(MAKE) build.o0
	$(MAKE) build.o1
	$(MAKE) build.o2
	$(MAKE) build.o3

build.o0:
	$(MAKE) $(EXE_0)

build.o1:
	$(MAKE) $(EXE_1)

build.o2:
	$(MAKE) $(EXE_2)

build.o3:
	$(MAKE) $(EXE_3)

$(EXE_0): $(SRC)
	arm-linux-gnueabi-gcc -marm -g $(OPT_0) -o $@ $< 

$(EXE_1): $(SRC)
	arm-linux-gnueabi-gcc -marm -g $(OPT_1) -o $@ $< 

$(EXE_2): $(SRC)
	arm-linux-gnueabi-gcc -marm -g $(OPT_2) -o $@ $< 

$(EXE_3): $(SRC)
	arm-linux-gnueabi-gcc -marm -g $(OPT_3) -o $@ $< 

run: $(EXE_0) $(EXE_1) $(EXE_2) $(EXE_3)
	$(MAKE) run.o0
	$(MAKE) run.o1
	$(MAKE) run.o2
	$(MAKE) run.o3

run.o0: $(EXE_0)
	-QEMU_LD_PREFIX=/usr/arm-linux-gnueabi $(QEMU_RUNNER) $(EXE_0)

run.o1: $(EXE_1)
	-QEMU_LD_PREFIX=/usr/arm-linux-gnueabi $(QEMU_RUNNER) $(EXE_1)

run.o2: $(EXE_2)
	-QEMU_LD_PREFIX=/usr/arm-linux-gnueabi $(QEMU_RUNNER) $(EXE_2)

run.o3: $(EXE_3)
	-QEMU_LD_PREFIX=/usr/arm-linux-gnueabi $(QEMU_RUNNER) $(EXE_3)

bir.o0: $(EXE_0)
	bap $(EXE_0) -d --no-cache --print-symbol=$(FUNC) > $(BIR_0)

bir.o1: $(EXE_1)
	bap $(EXE_1) -d --no-cache --print-symbol=$(FUNC) > $(BIR_1)

bir.o2: $(EXE_2)
	bap $(EXE_2) -d --no-cache --print-symbol=$(FUNC) > $(BIR_2)

bir.o3: $(EXE_3)
	bap $(EXE_3) -d --no-cache --print-symbol=$(FUNC) > $(BIR_3)

dasm.o0: $(EXE_0)
	arm-linux-gnueabi-objdump -DSshg $(EXE_0) > $(DASM_0)

dasm.o1: $(EXE_1)
	arm-linux-gnueabi-objdump -DSshg $(EXE_1) > $(DASM_1)

dasm.o2: $(EXE_2)
	arm-linux-gnueabi-objdump -DSshg $(EXE_2) > $(DASM_2)

dasm.o3: $(EXE_3)
	arm-linux-gnueabi-objdump -DSshg $(EXE_3) > $(DASM_3)
