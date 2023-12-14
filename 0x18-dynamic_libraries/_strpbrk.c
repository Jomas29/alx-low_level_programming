/*
 * _strpbrk - Searches a string for any of a set of bytes
 * @s: The string to be searched
 * @accept: The set of bytes to search for
 *
 * Return: A pointer to the first occurrence in s of any character in accept, or NULL if not found.
 */
char *_strpbrk(char *s, char *accept) {
    while (*s) {
        if (strchr(accept, *s))
            return s;
        s++;
    }
    return NULL;
}

