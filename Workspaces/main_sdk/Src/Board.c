#include "Board.h"

/* Constructor */
struct Board *createBoard(const char *name)
{
    struct Board *board_ptr = malloc(sizeof(*board_ptr));
    if (board_ptr != 0)
    {
        board_ptr->name = (uint8_t *)name;
        board_ptr->getBoardName = &getBoardName;
    }
    return board_ptr;
}

uint8_t *getBoardName(struct Board *self)
{
    return self->name;
}