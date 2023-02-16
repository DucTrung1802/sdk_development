#include <Debugger.h>

/* Constructor */
struct Debugger *createDebugger()
{
    struct Debugger *debugger_ptr = malloc(sizeof(*debugger_ptr));
    if (debugger_ptr != NULL)
    {
        debugger_ptr->writeLog = &writeLog;
        debugger_ptr->sendLog = &sendLog;
    }
    return debugger_ptr;
}

/* Destructor */
void destroyDebugger(struct Debugger *self)
{
    if (self != NULL)
    {
        free(self);
    }
}

/* Methods */
void writeLog(const char *log_content)
{
}

void sendLog()
{
}