/*
 * _puts - Writes a string to the standard output
 * @s: The string to be written
 *
 * Return: None
 */
void _puts(char *s) {
    while (*s) {
        _putchar(*s);
        s++;
    }
    _putchar('\n');
}

