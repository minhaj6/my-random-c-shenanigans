#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main() {
	int values[] = {10, 20, 30, 40, 50};
	int *vars[5];
	char *var_names[5];

	for (int i=0; i<5; i++) {
		char var_name[10];
		sprintf(var_name, "var%i", i+1);
		var_names[i] = (char *) malloc(strlen(var_name)+1);
		strcpy(var_names[i], var_name);
		vars[i] = (int *) malloc(sizeof(int));
		*(vars[i]) = values[i];
	}

	for (int i=0; i<5; i++) {
		printf("%s: ", var_names[i]);
		printf("%i \n", *vars[i]);
	}

	for (int i=0; i<5; i++) {
		free(vars[i]);
		free(var_names[i]);
	}
}
