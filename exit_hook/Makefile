CC=gcc
CFLAGS=-Wall -g
BIN=exit_hook

# $(CC) $(CFLAGS) $< -o $@

all: $(BIN)

%: %.c
	$(CC) $(CFLAGS) $<

clean:
	rm -rf *.out $(EXE)