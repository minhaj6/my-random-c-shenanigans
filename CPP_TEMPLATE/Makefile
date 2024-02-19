CC=g++
CFLAGS=-Wall -g
BIN=template

# $(CC) $(CFLAGS) $< -o $@

all: $(BIN)

%: %.c
	# $(CC) $(CFLAGS) $<
	$(CC) $(CFLAGS)

clean:
	rm -rf *.out $(EXE)
	find . -type f -executable -exec rm '{}' \;