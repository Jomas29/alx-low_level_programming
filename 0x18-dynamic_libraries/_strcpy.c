/*
 * _strcpy - Copies a string from source to destination
 * @dest: The destination buffer
 * @src: The source string
 *
 * Return: A pointer to the destination buffer.
 */
char *_strcpy(char *dest, char *src) {
    char *originalDest = dest;
    while (*src) {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
    return originalDest;
}

