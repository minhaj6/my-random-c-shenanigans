CC=gcc
CFLAGS=-Wall -g -O2
BIN?=0_Optimize

# $(CC) $(CFLAGS) $< -o $@

all: $(BIN)

%: %.c
	$(CC) $(CFLAGS) $<

clean:
	rm -rf *.out $(BIN)