CC=gcc
CFLAGS=-Wall -g -finstrument-functions
BIN?=profiler

# $(CC) $(CFLAGS) $< -o $@

all: $(BIN)

%: %.c
	$(CC) $(CFLAGS) $<

clean:
	rm -rf *.out $(BIN)