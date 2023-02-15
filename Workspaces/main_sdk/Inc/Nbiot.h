#ifndef NBIOT_H_
#define NBIOT_H_

#include <stdio.h>
#include <listEnum.h>

struct Nbiot
{
    uint8_t *imei;
    uint8_t *ccid;
    uint8_t *operator_code;
    uint8_t *operator_name;
    enum StatusType status;
};

#endif /* NBIOT_H_ */