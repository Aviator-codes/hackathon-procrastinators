#include "log.h"

void logError(const char* msg)
{
    printf("%s[ERROR]: %s%s%s\n", FG_RED, FG_MAGENTA, msg, ANSI_RESET);
    exit(EXIT_FAILURE);
}

void logWarning(const char* msg)
{
    printf("%s[WARNING]: %s%s%s\n", FG_YELLOW, FG_CYAN, msg, ANSI_RESET);
}

void logPass(const char* msg)
{
    printf("%s[PASSED]: %s%s%s\n", FG_GREEN, FG_BLUE, msg, ANSI_RESET);
}