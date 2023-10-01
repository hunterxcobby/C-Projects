#include "main.h"

/* CENTER ALIGN*/
void centerAlignText(const char *text) 
{
    int padding;
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    padding = (w.ws_col - strlen(text)) / 2;
    printf("%*s%s\n", padding, "", text);
}
