/*
 * _strstr - Locates a substring in another string
 * @haystack: The string to be searched
 * @needle: The substring to search for
 *
 * Return: A pointer to the beginning of the substring in the haystack, or NULL if not found.
 */
char *_strstr(char *haystack, char *needle) {
    while (*haystack) {
        char *start = haystack;
        char *pattern = needle;
        while (*haystack && *pattern && (*haystack == *pattern)) {
            haystack++;
            pattern++;
        }
        if (!*pattern)
            return start;
        haystack = start + 1;
    }
    return NULL;
}

