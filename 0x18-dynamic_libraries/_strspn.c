/*
 * _strspn - Calculates the length of the initial segment of s which consists only of bytes in accept
 * @s: The string to be searched
 * @accept: The string containing acceptable characters
 *
 * Return: The length of the initial segment of s consisting of only characters present in accept.
 */
unsigned int _strspn(char *s, char *accept) {
    unsigned int count = 0;
    while (*s && strchr(accept, *s)) {
        count++;
        s++;
    }
    return count;
}

