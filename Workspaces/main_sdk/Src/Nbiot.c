#include "Nbiot.h"

/* Constructor */
struct Nbiot *createNbiot(int tx_pin, int rx_pin)
{
    struct Nbiot *nbiot_ptr = malloc(sizeof(*nbiot_ptr));
    if (nbiot_ptr != 0)
    {
        /* TODO: Validate tx_pin, rx_pin */
        nbiot_ptr->tx_pin = tx_pin;
        nbiot_ptr->rx_pin = rx_pin;
    }
    return nbiot_ptr;
}

/* Destructor */
void destroyNbiot(struct Nbiot *self)
{
    if (self != NULL)
    {
        free(self);
    }
}