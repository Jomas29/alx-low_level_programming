#include "main.h"

int _putchar(char c);

void print_alphabet_x10(void) {
char letter = 'a';

for (int i = 0; i < 10; i++) {
for (int j = 0; j < 26; j++) {
_putchar(letter);
letter++;
}
letter = 'a'; // Reset letter to 'a' for the next line
_putchar('\n');
}
}
