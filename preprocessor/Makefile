CC=gcc
CFLAGS=-Wall -g

all: $(BINS)

%: %.c
	$(CC) $(CFLAGS) %^ -o $@

pre:
	$(CC) $(CFLAGS) -E macro.c

clean:
	$(RM) -r $(BINS) *.dSYM