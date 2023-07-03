#include <stddef.h>
/**
* _strstr - Locates a substring.
* @haystack: The string to search within.
* @needle: The substring to locate.
*
* Return: A pointer to the beginning of the located substring in @haystack,
*         or NULL if the substring is not found.
*/
char *_strstr(char *haystack, char *needle)
{
char *h_ptr, *n_ptr;

if (!*needle)
return (haystack);

while (*haystack)
{
h_ptr = haystack;
n_ptr = needle;

while (*n_ptr && *h_ptr && (*n_ptr == *h_ptr))
{
n_ptr++;
h_ptr++;
}

if (!*n_ptr)
return (haystack);

haystack++;
}

return (NULL);
}
