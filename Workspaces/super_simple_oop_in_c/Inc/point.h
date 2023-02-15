#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

struct point
{
    float x;
    float y;
    void (*point_setCoordinates)(struct point *self, float x, float y);
    float (*point_getXCoordinate)(struct point *self);
    float (*point_getYCoordinate)(struct point *self);
} point;

/* Constructor */
struct point *point_create(void);
/* Destructor */
void coordinate_destroy(struct point *self);

void point_setCoordinates(struct point *self, float x, float y);

float point_getXCoordinate(struct point *self);

float point_getYCoordinate(struct point *self);