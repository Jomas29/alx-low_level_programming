/*
 * _strcat - Concatenates two strings
 * @dest: The destination string
 * @src: The source string to be appended to dest
 *
 * Return: A pointer to the resulting string (dest).
 */
char *_strcat(char *dest, char *src) {
    char *originalDest = dest;
    while (*dest)
        dest++;
    while (*src) {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
    return originalDest;
}

