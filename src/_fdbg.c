#include <stdio.h>
#include <stdarg.h>

int fdbg(char* msg, ...) {
    va_list args;
    va_start(args, msg);
    FILE* f = fopen("fdbg.txt", "ab");
    vfprintf(f, msg, args);
    fprintf(f, "\n");
    fclose(f);
    return 0;
}
