/*
 * _strncat - Concatenates n characters from src to dest
 * @dest: The destination string
 * @src: The source string to be appended to dest
 * @n: The maximum number of characters to concatenate
 *
 * Return: A pointer to the resulting string (dest).
 */
char *_strncat(char *dest, char *src, int n) {
    char *originalDest = dest;
    while (*dest)
        dest++;
    while (*src && n > 0) {
        *dest = *src;
        dest++;
        src++;
        n--;
    }
    *dest = '\0';
    return originalDest;
}

