#ifndef BOARD_H_
#define BOARD_H_

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <listEnum.h>

#include <Nbiot.h>
#include <Debugger.h>
struct Board
{
    /* Attributes */
    uint8_t *name;
    enum StatusType status;
    struct Nbiot connector;
    struct Debugger debugger;
    // struct Ota ota;
    // struct Data data;

    /* Methods */
    uint8_t *(*getBoardName)(struct Board *self);
} Board;

/* Constructor */
struct Board *createBoard(const char *name);

/* Destructor */
void destroyBoard(struct Board *self);

/* Methods */
uint8_t *getBoardName(struct Board *self);

#endif /* BOARD_H_ */