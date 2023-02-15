#ifndef DEBUGGER_H_
#define DEBUGGER_H_

#include <stdio.h>

struct Debugger
{
    uint8_t *imei;
    uint8_t *ccid;
    uint8_t *operator_code;
    uint8_t *operator_name;
} Debugger;

#endif /* DEBUGGER_H_ */