/*
structs in c++ can hold member functions, 
unlike c structs.
*/
#include <stdio.h>
#include <cstring>

struct Person {
    int age;
    double height;
    char name[30];
    
    // overloading operator = 
    Person& operator= (Person& other) {
        age = other.age;
        height = other.height;
        strncpy(name, "NONAME", strlen("NONAME")+1);
        return *this;
    }
};

typedef struct Person person;

void print_person(const person *p) {
    printf("Person: %s (%d years old & %0.2lf ft tall)\n",
            p->name, p->age, p->height);
}

int main(void) {
    person person1, person2;
    
    person1.age = 30;
    person1.height = 5.10;
    strncpy(person1.name, "Minhaj", sizeof(person1.name));

    person2 = person1;

    print_person(&person1);
    print_person(&person2);

    return 0;
}