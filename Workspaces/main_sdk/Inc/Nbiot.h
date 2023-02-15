#ifndef NBIOT_H_
#define NBIOT_H_

#include <stdio.h>
#include <stdlib.h>
#include <listEnum.h>

struct Nbiot
{
    /* Attributes */
    int tx_pin;
    int rx_pin;
    uint8_t *imei;
    uint8_t *ccid;
    uint8_t *operator_code;
    uint8_t *operator_name;
    enum StatusType status;

    /* Methods */
    void (*regist)(struct Nbiot *self);
    void (*sendCommand)(struct Nbiot *self);
} Nbiot;

/* Constructor */
struct Nbiot *createNbiot(int tx_pin, int rx_pin);

/* Destructor */
void destroyNbiot(struct Nbiot *self);

/* Methods */
void regist(struct Nbiot *self);

void sendCommand(struct Nbiot *self);

#endif /* NBIOT_H_ */