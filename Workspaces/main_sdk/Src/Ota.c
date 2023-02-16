#include "Ota.h"

/* Constructor */
struct Ota *createOta()
{
    struct Ota *ota_ptr = malloc(sizeof(struct Ota));
    if (ota_ptr != 0)
    {
        ota_ptr->check = &check;
        ota_ptr->update = &update;
    }
}

/* Destructor */
void destroyOta(struct Ota *self)
{
    if (self != NULL)
    {
        free(self);
    }
}

/* Methods */
bool check(struct Ota *self, const char *content)
{
}

void update(struct Ota *self, const char *content)
{
}