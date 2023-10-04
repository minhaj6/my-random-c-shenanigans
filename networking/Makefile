CC=gcc
CFLAGS=-Wall -g
BIN=0_libcurl

# $(CC) $(CFLAGS) $< -o $@

all: $(BIN)

%: %.c
	$(CC) $(CFLAGS) $< -lcurl

clean:
	rm -rf *.out $(EXE)