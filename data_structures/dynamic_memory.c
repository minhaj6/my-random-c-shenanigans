#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#define CHUNKSIZE 2

char *getln() {
	char *line = NULL, *tmp = NULL;
	size_t size = 0, index = 0; int ch = EOF;

	while (ch) {
		ch = getc(stdin);              // read one char from input

		if (ch == EOF || ch == '\n')   // end string if EOF or newline
			ch = 0;

	/* if array index is getting bigger than already allocated memory then assign
	 * more memory (CHUNKSIZE byte) at a time, keep growing
	 */
		if (size <= index) {       
			size += CHUNKSIZE;    
			tmp = realloc(line, size);   // reallocating memory newsize
			
			if (!tmp) {    // break if realloc returns NULL
				free(line); 
				printf("BOOOOOOOOOM");
				line = NULL; 
				break;
			}
			line = tmp;
		}

		line[index++] = ch;
	}
	return line;
}

int main() {
	char *line = getln();

	printf("%s \n", line);

}
