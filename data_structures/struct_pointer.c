#include <stdio.h>
#include <string.h>

struct Complex {
	int imag;
	int real;
};

struct Person {
	char name[50];
	int age;
	
	struct Complex salary;
};

int main() {
	struct Person *personPtr, p1;
	personPtr = &p1;

	strcpy(personPtr->name, "Minhaj Shovon");
	
	personPtr->age = 23;
	p1.salary.imag = 5000000;
	p1.salary.real = 50;

	printf("Name: %s \n", personPtr->name;
	printf("Age: %d \n", personPtr->age);
	printf("Salary: %i + %i i \n", p1.salary.real, p1.salary.imag);

	return 0;
}
