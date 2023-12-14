/*
 * _strchr - Locates the first occurrence of a character in a string
 * @s: The string to be searched
 * @c: The character to be located
 *
 * Return: A pointer to the first occurrence of the character c in the string s, or NULL if not found.
 */
char *_strchr(char *s, char c) {
    while (*s) {
        if (*s == c)
            return s;
        s++;
    }
    return (*s == c) ? s : NULL;
}

