CC=gcc
CFLAGS=-Wall -g
BIN=0_progress

# $(CC) $(CFLAGS) $< -o $@

all: $(BIN)

%: %.c
	$(CC) $(CFLAGS) $<

clean:
	rm -rf *.out $(EXE)