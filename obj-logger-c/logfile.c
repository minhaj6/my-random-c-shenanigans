#include "log.h"
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

int file_init(logger *self, void *data);
void file_info(logger *self, char *str);
void file_error(logger *self, char *str);
void file_close(logger *self);

log_interface file_interface = {
    .init = file_init;
    .info = file_info;
    .error = file_error;
    .close = file_close;
};

// under abstraction
typedef struct filelog_data_ {
    char *filename;
    FILE *fd;
} filelog_data;

int file_init(logger *self, void *data) {
    self->interface = &file_interface;
    self->data = data;

    filelog_data *fld = data;
    fld->fd = fopen(fld->filename, "w");

    printf("File logger init: %s - %p\n", fld->filename, fld->fd);

    if (!fld->fd) {
        return errno;
    }
    
    return 0;
}