#ifndef OTA_H_
#define OTA_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Ota
{
    /* Attributes */
    uint8_t *file_path;

    /* Methods */
    bool (*check)(struct Ota *self, const char *content);
    void (*update)(struct Ota *self, const char *content);
} Ota;

/* Constructor */
struct Ota *createOta();

/* Destructor */
void destroyOta(struct Ota *self);

/* Methods */
bool check(struct Ota *self, const char *content);

void update(struct Ota *self, const char *content);

#endif