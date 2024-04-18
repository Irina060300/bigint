#include <stdio.h>
#include <stdlib.h>
#include <string.h> <> !!!!
char *input() {
    char *input_number = malloc(sizeof(char));
    ;
    char c = '\0';
    int i = 0;
    while (c != '\n') {
        c = getchar();
        input_number = realloc(input_number, i + 1);
        input_number[i] = c;
        i++;
    }
    input_number[i - 1] = '\0';
    return input_number;
}
void clean(char *str) {
    size_t len = strlen(str);
    size_t i = 0;
    if (str[i] == '-') i = 1;
    size_t count = 0;
    while (str[i] == '0') {
        i++;
        count++;
    }
    if (count > 0) {
        if (str[0] != '-') {
            i = 0;
            if (count == len) count -= 1;
        } else {
            if (count == len - 1) {
                i = 0;
            } else {
                i = 1;
            }
        }
        while (i <= len) {
            str[i] = str[i + count];
            i++;
        }
    }
    str[len - count] = '\0';
}
int is_number(char *str) {
    int flag = 0;
    size_t len_str = strlen(str);
    for (size_t i = 0; i < len_str; i++) {
        if (!(strchr("-0123456789", str[i]))) flag++;
        if (str[i] == '-' && i != 0) {
            flag++;
            printf("i = %lu, flag = %d\n", i, flag);
        }
    }
    return flag;
}

void create_new(char *str, char *new_str, size_t len) {
    int def_str = (int)len - strlen(str);
    int i;
    int ln = (int)len;
    for (i = ln - 1; i >= 0; i--) {
        if ((i - def_str >= 0) && str[i - def_str] != '-') {
            new_str[i] = str[i - def_str];
        } else {
            new_str[i] = '0';
        }
    }
}

void sum(char *new_a, char *new_b, char *a, char *b, char *result, size_t len) {
    int i;
    int c = 0, d = 0, cel = 0;
    int ln = (int)len;
    for (i = ln - 1; i >= 0; i--) {
        cel = (c + d + cel) / 10;
        c = (int)new_a[i] - 48;
        d = (int)new_b[i] - 48;
        result[i] = (char)(c + d + cel) % 10 + 48;
        // printf("%c\n", result[i]);
    }
    if (a[0] == '-' && b[0] == '-') {
        result[0] = '-';
    }
}

int main() {
    char *a, *b, *new_a, *new_b, *result;
    a = input();
    b = input();
    char sign;
    scanf("%c", &sign);
    if (a && b && is_number(a) == 0 && is_number(b) == 0) {
        clean(a);
        clean(b);
        size_t len = 0;
        switch (sign) {
            case '+':
                if ((a[0] == '-' && b[0] == '-') || (a[0] != '-' && b[0] != '-')) {
                    size_t len_a = strlen(a), len_b = strlen(b);
                    if (len_a > len_b) {
                        len = len_a + 3;
                    } else {
                        len = len_b + 3;
                    }
                    new_a = malloc(len * sizeof(char));
                    new_b = malloc(len * sizeof(char));
                    create_new(a, new_a, len);
                    create_new(b, new_b, len);
                    result = malloc(len * sizeof(char));
                    sum(new_a, new_b, a, b, result, len);
                    clean(result);
                    printf("%s", result);
                }
                break;
            case '-':
                /* code */
                break;
            case '*':
                /* code */
                break;
            case '/':
                /* code */
                break;

            default:
                printf("MISTAKE!!!");
                break;
        }
        free(a);
        free(b);
        free(new_a);
        free(new_b);
        free(result);
    } else {
        printf("MISTAKE!!!");
    }
    return 0;
}
