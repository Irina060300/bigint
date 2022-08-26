#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *input_a();
char *input_b();
int check_input(char *a, char *b);
char *sum(char *a, char *b, int len);
char *create_new(char *b, int len);
int test_calc(char *a, char *b, int len);

char *input_a() {
    char *a = malloc(sizeof(char));
    char c;
    int i = 0;
    while (c != '\n') {
        c = getchar();
        a = realloc(a, i + 1);
        a[i] = c;
        i++;
    }
    a[i - 1] = '\0';
    return a;
}

char *input_b () {
    char *b = malloc(sizeof(char));
    char c;
    int i = 0;
    while (c != '\n') {
        c = getchar();
        b = realloc(b, i + 1);
        b[i] = c;
        i++;
    }
    b[i - 1] = '\0';
    return b;
}


int main() {
    // char *a = malloc(sizeof(char));
    char *a = input_a();
    // char *b = malloc(sizeof(char));
    char *b = input_b();
    // char c;
    // size_t i = 0;
    // while (c != '\n') {
    //     c = getchar();
    //     a = realloc(a, i + 1);
    //     a[i] = c;
    //     i++;
    // }
    // a[i - 1] = '\0';
    // int i;
    // char c;
    // i = 0;
    // c = ' ';
    // while (c != '\n') {
    //     c = getchar();
    //     b = realloc(b, i + 1);
    //     b[i] = c;
    //     i++;
    // }
    // b[i - 1] = '\0';

    char sign;
    scanf("%c", &sign);

    if (check_input(a, b) == 0 && sign == '+' || sign == '-' || sign == '*' || sign == '/') {
        if (sign == '+') {
            char *result;
            char *new_a, *new_b, *test_a, *test_b;
            int len_a = strlen(a);
            int len_b = strlen(b);
            int len;
            if (len_a > len_b) {
                test_b = create_new(b, len_a);
                if (test_calc(a, test_b, len_a) == len_a)
                    len = len_a + 1;
                else
                    len = len_a;
            } else if (len_b > len_a) {
                test_a = create_new(a, len_b);
                if (test_calc(test_a, b, len_b) == len_b)
                    len = len_b + 1;
                else
                    len = len_b;
            } else {
                if (test_calc(a, b, len_a) == len_a)
                    len = len_a + 1;
                else
                    len = len_a;
            }
            // new_a = malloc(len * sizeof(char));
            // new_b = malloc(len * sizeof(char));
            new_a = create_new(a, len);
            new_b = create_new(b, len);
            result = sum(new_a, new_b, len);
            printf("sum = %s", result);
        }
    } else
        printf("n/a");
    return 0;
}

int check_input(char *a, char *b) {
    int flag = 0;
    size_t len_a = strlen(a), len_b = strlen(b);
    for (size_t i = 0; i < len_a; i++) {
        if (!(strchr("-0123456789", a[i]))) flag++;
        if (a[i] == '-' && i != 0) flag++;
    }
    for (size_t i = 0; i < len_b; i++) {
        if (!(strchr("-0123456789", b[i]))) flag++;
        if (b[i] == '-' && i != 0) flag++;
    }
    return flag;
}

char *sum(char *a, char *b, int len) {
    char *result = malloc(len * sizeof(char));
    // printf("new_a %s\nnew_b %s\n", a, b);
    if (a[0] != '-' && b[0] != '-') {
        int c = 0, d = 0, cel = 0, i;
        int len_a = strlen(a);
        int def = len - len_a;
        for (i = len - 1; i >= 0; i--) {
            c = (int)a[i - def] - 48;
            d = (int)b[i - def] - 48;
            result[i] = (char)(c + d + cel) % 10 + 48;
            // printf("%c %d\n", result[i], i);
            cel = (c + d + cel) / 10;
        }
        // printf("%d\n", cel);
        if (cel > 0)
            result[0] = (char)(c + d + cel) % 10 + 48;
    }
    // printf("%s", result);
    return result;
}

char *create_new(char *b, int len) {
    int def_b = len - strlen(b);
    char *new_b = malloc(len * sizeof(char));
    for (int i = len - 1; i >= 0; i--) {
        if (i - def_b >= 0) {
            new_b[i] = b[i - def_b];
        } else {
            new_b[i] = '0';
        }
    }
    return new_b;
}

int test_calc(char *a, char *b, int len) {
    int flag = 0;
    if (a[0] != '-' && b[0] != '-') {
        int c = 0, d = 0, cel = 0, i;
        int len_a = strlen(a);
        int def = len - len_a;
        for (i = len - 1; i >= 0; i--) {
            c = (int)a[i - def] - 48;
            d = (int)b[i - def] - 48;
            if ((c + d + cel) / 10 == 1) flag++;
            // printf("c %d d %d cel %d i %d flag %d\n", c, d, cel, i, flag);
            cel = (c + d + cel) / 10;
        }
    }
    return flag;
}
// int main() {
//     char c;
//     int i = 0;
//     char *a = input_a();
//     char *b = input_b();
//         printf("\n%s", a);
//     // else
//     //     printf("n/a");
//     return 0;
// }

// char *input_a() {
//     char c;
//     char *a;
//     int i = 0;
//     a = NULL;
//     while (c != '\n') {
//         c = getchar();
//         a = realloc(a, i + 1);
//         printf("%p  ", &a[i]);
//         a[i] = c;
//         i++;
//     }
//     a[i - 1] = '\0';
//     printf("%p  ", &a[i]);
//     return a;
// }

// char *input_b() {
//     char c;
//     char *b = NULL;
//     int i = 0;
//     while (c != '\n') {
//         c = getchar();
//         b = realloc(b, i + 1);
//         b[i] = c;
//         printf("%c %d\n", b[i], i);
//         i++;

//     }
//     b[i - 1] = '\0';
//     return b;
// }