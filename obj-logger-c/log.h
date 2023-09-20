#pragma once

typedef struct logger_ logger;

// function interface
typedef struct log_interface_ {
    int (*init)(logger *self, void *data);
    void (*info)(logger *self, char *str);
    void (*error)(logger *self, char *str);
    void (*close)(logger *self);
} log_interface;

struct logger_ {
    log_interface *interface;
    void *data;
};

extern logger conlog;
