#include <stdio.h>
#include <stdlib.h> 	/* gives malloc() */

typedef struct {
	void *next;
	int data;
} Node;

Node *head = NULL;

/* add a node */
Node *add_node(int data) {
	Node *new = NULL;

	if (head == NULL){
		new = malloc(sizeof(Node));
		if (new == NULL) return NULL;

		new->data = data;
		head = new;
		new->next = NULL;
	} else {
		new = malloc(sizeof(Node));
		if (new == NULL) return NULL;

		new->data = data;
		new->next = head;
		head = new;
	}
	return new;
}

/* delete a node */
int delete_node(int data) {
	Node *current = head;
	Node *prev = head;
	while (current != NULL) {
		if (current->data == data) {
			if (current == head) {
				head = current->next;
			} else {
				prev->next = current->next;
			}
			free(current);
			current = NULL;
			return 1;   		/* we found the data and removed it */
		}
		prev = current;
		current = current->next;
	}
	return 0; 					/* we didn't find the data */
}

/* insert a node into a position */
/* print the list */
void print_list() {
	Node *current = head;
	while (current != NULL) {
		printf("%d->", current->data);
		current = current->next;
	}
	printf("\n");
}

void print_menu() {
	printf("Choose any of the following operation:\n");
	printf("\t1. Add a node to the list.\n");
	printf("\t2. Remove a node from the list.\n");
	printf("\t3. Insert a node to a position in the list.\n");
	printf("\t4. Print the list.\n");
	printf("\t5. Quit.\n");
}

int main(int argc, char **argv) {
	print_menu();
	
	int user_input;
	int option = -1;
	while (option != 5) {
		int scan = scanf("%d", &option);
		if (scan == 1 && option > 0 && option < 6) {
			switch(option) {
				case 1:
					// add a node to the list
					printf("Enter data you want to add: ");
					scanf("%d", &user_input);
					add_node(user_input);
					break;

				case 2:
					// Remove a node from the list
					printf("Enter data you want to remove: ");
					scanf("%d", &user_input);
					int success = delete_node(user_input);
					if (!success) {
						printf("Element not found.\n");
					}
					break;

				case 3:
					// Insert a node to a position in the list
					break;
				case 4:
					print_list();
					break;

				case 5:
					// Quit
					break;
			}
		} else printf("I fucked up\n");
	}

	return 0;
}
