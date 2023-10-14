CC=gcc
CFLAGS=-g -Wall
OBJS=IPC_shared_mem.o
BIN=IPC_write_sharedmem.elf IPC_read_sharedmem.elf IPC_destory_sharedmem.elf

all: $(BIN)

%.elf: %.o $(OBJS)
	$(CC) $(CFLAGS) $< $(OBJS) -o $@

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf *.o $(BIN)