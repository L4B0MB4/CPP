#include <stdarg.h>
char* Printf(char* dst, const void* end, const char* fmt, va_list vl);
void getString(char type, void* param, char* buffer, const int buffermaxlen);
void decimalToBinary(void* param, char* buffer, const int buffermaxlen);