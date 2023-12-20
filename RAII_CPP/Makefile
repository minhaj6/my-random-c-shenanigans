CC=g++
CFLAGS=-Wall -g
BIN=0_raii

# $(CC) $(CFLAGS) $< -o $@

all: $(BIN)

%: %.c
	$(CC) $(CFLAGS) $<

clean:
	rm -rf *.out $(EXE)
	find . -type f -executable -exec rm '{}' \;