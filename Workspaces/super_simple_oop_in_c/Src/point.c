#include "point.h"

/* Constructor */
struct point *point_create(void)
{
    struct point *c = malloc(sizeof(*c));
    if (c != 0)
    {
        c->point_setCoordinates = &point_setCoordinates;
        c->point_getXCoordinate = &point_getXCoordinate;
        c->point_getYCoordinate = &point_getYCoordinate;
        c->x = 0;
        c->y = 0;
    }
    return c;
}

/* Destructor */
void coordinate_destroy(struct point *self)
{
    if (self != NULL)
    {
        free(self);
    }
}

void point_setCoordinates(struct point *self, float x, float y)
{
    self->x = x;
    self->y = y;
}

float point_getXCoordinate(struct point *self)
{
    return self->x;
}

float point_getYCoordinate(struct point *self)
{
    return self->y;
}
