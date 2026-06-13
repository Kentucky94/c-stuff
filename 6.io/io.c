#include <stdio.h>

void example_1() {
    int c;
    c = getchar();

    while (c != EOF) { // until end of file (to imitate it use Ctrl + D)
        if(c == '\n') {
            printf("OK\n");
        }

        c = getchar();
    }
}

void example_2() { // shorter version
    int c;
    while ((c = getchar()) != EOF) { // until end of file (to imitate it use Ctrl + D)
        if(c == '\n') {
            printf("OK\n");
        }
    }
}

void example_3() { // with string count
    int c, l;
    l = 0;
    while ((c = getchar()) != EOF) { // until end of file (to imitate it use Ctrl + D)
        if(c == '\n') {
            printf("Lenght is: %d\n", l);
            l = 0;
            continue;
        }
        l++;
    }
}

void until_space() {
    int c, pr;
    pr = 1; // true
    while ((c = getchar()) != EOF) { // until end of file (to imitate it use Ctrl + D)
        switch(c) {
            case '\n':
                putchar('\n');
                pr = 1;
                break;
            case ' ':
                pr = 0;
                break;
            default:
                if (pr) {
                    putchar(c);
                }
        }
    }
}

int main() {
    until_space();
    
    return 0;
}