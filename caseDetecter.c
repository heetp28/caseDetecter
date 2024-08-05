#include <stdio.h>
#include <ctype.h>  // For isupper(), islower(), and isalpha()
#include <string.h>

void detect_case(const char *str) {
    while (*str) {
        if (isupper(*str)) {
            printf("'%c' is uppercase\n", *str);
        } else if (islower(*str)) {
            printf("'%c' is lowercase\n", *str);
        } else if (isalpha(*str)) {
            printf("'%c' is a letter but not uppercase or lowercase\n", *str);
        } else {
            printf("'%c' is not a letter\n", *str);
        }
        str++;
    }
}

int main() {
    char input[100];
    
    printf("Enter a string: ");
    if (fgets(input, sizeof(input), stdin) != NULL) {
        // Remove newline character if present
        size_t len = strlen(input);
        if (len > 0 && input[len - 1] == '\n') {
            input[len - 1] = '\0';
        }
        detect_case(input);
    } else {
        printf("Error reading input.\n");
    }

    return 0;
}
