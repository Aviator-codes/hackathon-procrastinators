#pragma once
#include "../config.h"

#define ANSI_ESC "\x1b["
#define ANSI_RESET ANSI_ESC "0m"
#define ANSI_CLEAR "\033[2J\033[1;1H"

#define FG_BLACK   ANSI_ESC "30m"
#define FG_RED     ANSI_ESC "31m"
#define FG_GREEN   ANSI_ESC "32m"
#define FG_YELLOW  ANSI_ESC "33m"
#define FG_BLUE    ANSI_ESC "34m"
#define FG_MAGENTA ANSI_ESC "35m"
#define FG_CYAN    ANSI_ESC "36m"
#define FG_WHITE   ANSI_ESC "37m"

void logError(const char* msg);

void logWarning(const char* msg);

void logPass(const char* msg);