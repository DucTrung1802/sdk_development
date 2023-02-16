#include "Data.h"

/* Constructor */
struct Data *createData(int value)
{
    struct Data *data_ptr = malloc(sizeof(struct Data));
    if (data_ptr != NULL)
    {
        data_ptr->setValue = &setValue;
        data_ptr->getValue = &getValue;
    }
}

/* Destructor */
void destroyData(struct Data *self)
{
    if (self != NULL)
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
