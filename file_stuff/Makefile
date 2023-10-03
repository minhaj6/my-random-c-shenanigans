CC=gcc
CFLAGS=-Wall -g
BIN=jpgfiletest

# $(CC) $(CFLAGS) $< -o $@

all: $(BIN)

%: %.c
	$(CC) $(CFLAGS) $<

clean:
	rm -rf *.out $(EXE)
