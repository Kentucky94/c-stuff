#include <stdio.h>
#include <stdlib.h>

int get_str_len (const char *str) { // const is needed to explain to compiler that memory is read-only
    int i = 0;
    
    for (; str[i]; i++) {
        printf("Symbol: %c\n", str[i]);
    }

    return i;
}

int get_str_len2 (const char *str) { // const is needed to explain to compiler that memory is read-only
    int i = 0;
    // char symbol = str[i];
    
    while (str[i] != '\0') {  // single quotes are a must
        printf("Symbol: %c\n", str[i]);
        //printf("Symbol: %c\n", symbol); // will not dynamically change
        i++;
    }

    return i;
}

void string_copy (char *dest, const char *src) {
    int i = 0;
    for (; src[i] != '\0'; i++) {
        printf("Copying symbol: %c\n", src[i]);
        dest[i] = src[i];
    }
    dest[i] = 0; // proper string must end with 0
}

void string_copy_2 (char *dest, const char *src) {
    while (*src) {
        printf("Copying symbol: %c\n", *src);
        *dest = *src;
        src++;
        dest++;
    }
    *dest = 0;
}

int main () {
    char str[] = "Testing string";

    int count = get_str_len2(str);
    printf("Result: %d\n", count);

    char copy[count];

    //string_copy(copy, str);
    string_copy_2(copy, str);
    printf("Copied string: %s\n", copy);

    //char *danger = 'Danger'; // not the same as char danger[]
    //danger[4] = 0; // causes emergency error

    return 0;
}