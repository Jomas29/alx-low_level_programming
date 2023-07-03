/**
* _memcpy - Copies a memory area.
* @dest: Pointer to the destination memory area.
* @src: Pointer to the source memory area.
* @n: Number of bytes to copy.
*
* Return: A pointer to the destination memory area @dest.
*/
char *_memcpy(char *dest, char *src, unsigned int n)
{
char *original_dest = dest;

while (n > 0)
{
*dest = *src;
dest++;
src++;
n--;
}

return (original_dest);
}
