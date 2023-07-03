/**
* _strspn - Gets the length of a prefix substring.
* @s: The string to search.
* @accept: The string containing the characters to match.
*
* Return: The number of bytes in the initial segment of @s consisting only of
*         bytes from @accept.
*/

unsigned int _strspn(char *s, char *accept)
{
unsigned int count = 0;
int found;

char *a;

while (*s)
{
found = 0;
for (a = accept; *a; a++)
{
if (*s == *a)
{
found = 1;
break;
}
}

if (!found)
return (count);

count++;
s++;
}

return (count);
}
