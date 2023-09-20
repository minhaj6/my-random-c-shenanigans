#pragma once

typedef struct ANIMAL_STUCT {
    char *speech;
    void* (*speak)(struct ANIMAL_STRUCT *self);
} Animal;

Animal *animal_constructor(Animal *animal, char *speech);

void animal_speak(Animal *animal);