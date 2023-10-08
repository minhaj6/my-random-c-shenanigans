CC=g++
CFLAGS=-Wall -g
BIN?=overloading_operator

# $(CC) $(CFLAGS) $< -o $@

all: $(BIN)

%: %.c
	$(CC) $(CFLAGS) $< 

clean:
	rm -rf *.out $(BIN)