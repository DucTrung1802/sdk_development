#ifndef BOARD_H_
#define BOARD_H_

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

enum StatusType
{
    GOOD = 1,
    BAD = 0
};

struct Board
{
    /* Attributes */
    uint8_t *name;
    enum StatusType status;
    // struct Nbiot nbiot;
    // struct Debugger debugger;
    // struct Ota ota;
    // struct Data data;

    /* Methods */
    uint8_t *(*getBoardName)(struct Board *self);
} Board;

/* Constructor */
struct Board *createBoard(const char *name);

/* Destructor */
// void destroyBoard(struct Board *self);

/* Methods */
uint8_t *getBoardName(struct Board *self);

#endif /* BOARD_H_ */