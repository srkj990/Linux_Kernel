#include "Strings.h"

//Reversing a string
char* reverse_string(char *str)
{
    int length = strlen(str);
    if(!str)
    {
        return str;
    }
    char *start = str;
    char *end = str + length - 1;
    while(start < end)
    {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
    return str;
}