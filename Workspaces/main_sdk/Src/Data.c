#include "Data.h"

/* Constructor */
struct Data *createData(int value)
{
    struct Data *data_ptr = malloc(sizeof(struct Data));
    if (data_ptr != 0)
    {
        data_ptr->setValue = &setValue;
        data_ptr->getValue = &getValue;
    }
}

/* Destructor */
void destroyData(struct Data *self)
{
    if (self != 0)
    {
        free(self);
    }
}

/* Methods */
void setValue(struct Data *self, int value)
{
}

int getValue(struct Data *self)
{
}
