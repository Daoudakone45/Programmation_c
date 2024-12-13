#include <stdio.h>
#include <ctype.h>

void wc() {
    int char_count = 0;
    int word_count = 0;
    int line_count = 0;
    int in_word = 0;
    char c;

    while ((c = getchar()) != EOF) {
        char_count++;

        if (c == '\n') {
            line_count++;
        }

        if (isspace(c)) {
            in_word = 0;
        } else if (!in_word) {
            in_word = 1;
            word_count++;
        }
    }

    printf("Lines: %d\n", line_count);
    printf("Words: %d\n", word_count);
    printf("Characters: %d\n", char_count);
}

int main() {
    printf("Enter text (Ctrl+D to end):\n");
    wc();
    return 0;
}
