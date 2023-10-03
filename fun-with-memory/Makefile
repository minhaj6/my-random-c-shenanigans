CC=gcc
CFLAGS=-Wall -g
BIN=KMP_String

# $(CC) $(CFLAGS) $< -o $@

all: $(BIN)

%: %.c
	$(CC) $(CFLAGS) $<

clean:
	rm -rf *.out $(EXE)