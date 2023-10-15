CC=gcc
CFLAGS=-Wall -g
BIN?=locking


# $(CC) $(CFLAGS) $< -o $@

all: $(BIN)

%: %.c
	$(CC) $(CFLAGS) $<

clean:
	rm -rf *.out *.exe $(EXE)
