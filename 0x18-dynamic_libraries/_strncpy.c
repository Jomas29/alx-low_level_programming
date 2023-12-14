/*
 * _strncpy - Copies up to n characters from src to dest
 * @dest: The destination buffer
 * @src: The source string
 * @n: The maximum number of characters to copy
 *
 * Return: A pointer to the destination buffer.
 */
char *_strncpy(char *dest, char *src, int n) {
    char *originalDest = dest;
    while (*src && n > 0) {
        *dest = *src;
        dest++;
        src++;
        n--;
    }
    while (n > 0) {
        *dest = '\0';
        dest++;
        n--;
    }
    return originalDest;
}

