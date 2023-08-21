#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

/* _printf function prototype */
int _printf(const char *format, ...);

/* Handler function prototypes */
int handle_char(int c);
int handle_string(va_list args);
int handle_percent(void);
int handle_format_specifier(const char **format, va_list args);

#endif /* MAIN_H */
