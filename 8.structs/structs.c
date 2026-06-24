#include <stdio.h>
#include <stdlib.h>

enum { max_name_len = 64, max_group_len = 8 };

struct Student {
    char name[max_name_len];
    char gender; // 'm' or 'f'
    int year_of_birth;
    int major_code;
    char group[max_group_len];
    float average;
};

void string_copy (char *dest, const char *src) {
    int i = 0;
    while (src[i] != '\0') {
        printf("Copying symbol: %c\n", src[i]);
        dest[i] = src[i];
        i++;
    }
    dest[i] = 0; // proper string must end with 0
}

int main () {
    struct Student st1;

    string_copy(st1.name, "Ivan Ivanov");
    st1.gender = 'm';
    st1.year_of_birth = 1999;
    st1.major_code = 51236;
    string_copy(st1.group, "312");
    st1.average = 4.12;

    struct Student st2 = {
        "Pyotr Petrov",
        'm',
        1997,
        53215,
        "312",
        4.164
    };

    printf("%s\n", st1.name);
    printf("%s\n", st2.name);

    struct Student *ptr;
    ptr = malloc(sizeof(struct Student));
    // ptr = malloc(sizeof(*ptr))   also works

    ptr->year_of_birth = 1994;
    // (*ptr).year_of_birth = 1994; braces are necessary

    return 0;
}