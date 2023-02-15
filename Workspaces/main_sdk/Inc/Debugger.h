#ifndef DEBUGGER_H_
#define DEBUGGER_H_

#include <stdio.h>
#include <stdlib.h>

struct Debugger
{
    /* Attributes */
    uint8_t *file_path;

    /* Methods */
    void (*writeLog)(const char *log_content);
    void (*sendLog)(void);
} Debugger;

/* Constructor */
struct Debugger *createDebugger();

/* Destructor */
void destroyDebugger(struct Debugger *self);

/* Methods */
void writeLog(const char *log_content);

void sendLog();

#endif /* DEBUGGER_H_ */