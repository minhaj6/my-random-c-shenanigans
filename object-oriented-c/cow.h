#pragma once
#include "animal.h"

typedef struct COW_STRUCT {
    Animal base;
} Cow;

Cow *new_cow();