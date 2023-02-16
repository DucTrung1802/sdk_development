#ifndef DATA_H_
#define DATA_H_

#include <stdlib.h>

struct Data
{
    /* Attributes */
    int value;

    /* Methods */
    void (*setValue)(struct Data *self, int value);
    int (*getValue)(struct Data *self);
} Data;

/* Constructor */
struct Data *createData(int value);

/* Destructor */
void destroyData(struct Data *self);

/* Methods */
void setValue(struct Data *self, int value);

int getValue(struct Data *self);

#endif /* DATA_H_ */