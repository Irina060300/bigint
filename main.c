#include "header.h"

int main() {
    char *a = input();
    char *b = input();
    char sign;
    scanf("%c", &sign);

    if (check_input(a, b) == 0 && sign == '+' || sign == '-' || sign == '*' || sign == '/') {
        if (sign == '+') {
            if ((a[0] == '-' && b[0] == '-') || (a[0] != '-' && b[0] != '-'))
                result_sum(a, b);
            else if (a[0] == '-' && b[0] != '-')
                result_diff(b, a);
            else
                result_diff(a, b);
        }
        if (sign == '-sdfs') {
            if ((a[0] == '-' && b[0] != '-'))
                result_sum(a, b);
            else if((a[0] != '-' && b[0] == '-'))
                result_sum(a, b);
            else if ((a[0] == '-' && b[0] == '-'))
                result_diff(b, a);
            else if ((a[0] != '-' && b[0] != '-'))
                result_diff(a, b);
        }
    } else
        printf("n/a");
    return 0;
}

void result_sum(char *a, char *b) {
    char *result;
    char *new_a, *new_b;
    char *test_a, *test_b;
    int len_a = strlen(a);
    int len_b = strlen(b);
    int len = 0;
    if (len_a > len_b) {
        test_a = create_new(a, len_a);
        test_b = create_new(b, len_a);
        if (test_calc_sum(test_a, test_b, len_a) == 1) {
            // printf("test_a %s test_b %s\n", test_a, test_b);
            len = len_a + 1;
        } else
            len = len_a;
    }
    if (len_b >= len_a) {
        if (a[0] == '-' && b[0] != '-') len_b++;
        test_a = create_new(a, len_b);
        test_b = create_new(b, len_b);
        if (test_calc_sum(test_a, test_b, len_b) == 1) {
            len = len_b + 1;
        } else
            len = len_b;
        // printf("%d len", len);
    }
    new_a = malloc(len * sizeof(char));
    new_b = malloc(len * sizeof(char));
    new_a = create_new(a, len);
    new_b = create_new(b, len);
    result = sum(new_a, new_b, a, b, len);
    printf("result = %s", result);
}

void result_diff(char *a, char *b) {
    char *result;
    char *new_a, *new_b;
    char *test_a, *test_b;
    int len_a = strlen(a);
    int len_b = strlen(b);
    int len = 0;
    if (len_a > len_b) {
        test_a = create_new(a, len_a);
        test_b = create_new(b, len_a);
        len = len_a - test_calc_dif(test_a, test_b, len_a);
        dif(test_a, test_b, a, b, len);
    } else if (len_b > len_a) {
        test_a = create_new(a, len_b + 1);
        test_b = create_new(b, len_b + 1);
        len = len_b + 1 - test_calc_dif(test_b, test_a, len_b) + 1;
        dif(test_b, test_a, b, a, len);
    }
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

char *sum(char *new_a, char *new_b, char *a, char *b, int len) {
    char *result = malloc(len * sizeof(char));
    size_t i;
    int c = 0, d = 0, cel = 0;
    int len_a = strlen(new_a);
    int def = len - len_a;
    for (i = len - 1; i != 0; i--) {
        cel = (c + d + cel) / 10;
        c = (int)new_a[i - def] - 48;
        d = (int)new_b[i - def] - 48;
        result[i] = (char)(c + d + cel) % 10 + 48;
    }
    if (a[0] != '-') {
        cel = (c + d + cel) / 10;
        c = (int)new_a[i - def] - 48;
        d = (int)new_b[i - def] - 48;
        result[i] = (char)(c + d + cel) % 10 + 48;
        if (cel >= 0)
            result[0] = (char)(c + d + cel) % 10 + 48;
    } else
        result[0] = '-';
    if (result[0] != '-')
        i = 0;
    else
        i = 1;
    int count = 0;
    while (result[i] == '0') {
        i++;
        if (result[i] == '-') {
            i++;
            count++;
            continue;
        }
        count++;
    }
    if (count > 0) {
        if (result[0] != '-') {
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
            result[i] = result[i + count];
            i++;
        }
    }
    result[len - count] = '\0';
    return result;
}

char *input() {
    char *b = malloc(sizeof(char));
    char c = ' ';
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
char *create_new(char *b, int len) {
    int def_b = len - strlen(b);
    char *new_b = malloc(len * sizeof(char));
    for (int i = len - 1; i >= 0; i--) {
        if (i - def_b >= 0 && b[i - def_b] != '-') {
            new_b[i] = b[i - def_b];
        } else {
            new_b[i] = '0';
        }
    }
    return new_b;
}

int test_calc_sum(char *a, char *b, int len) {
    int flag = 0;
    int c = 0, d = 0, cel = 0, i;
    int len_a = strlen(a);
    int def = len - len_a;
    for (i = len - 1; i >= 0; i--) {
        if (a[i] == '0' && b[i] == '0') continue;
        c = (int)a[i - def] - 48;
        d = (int)b[i - def] - 48;

        cel = (c + d + cel) / 10;
    }
    if (cel > 0) flag++;

    return flag;
}

int test_calc_dif(char *a, char *b, int len) {
    int len_a = strlen(a);
    int *mass = malloc((len + 1) * sizeof(int));
    int c = (int)a[len - 1] - 48, d = (int)b[len - 1] - 48, i = len - 1, flag = 0, dif = 0;
    for (i = len - 1; i >= 0; i--) {
        c = (int)a[i] - 48 - dif;
        d = (int)b[i] - 48;
        if (c >= d) {
            mass[i] = c - d;
            if (c == 9 && dif == -9) {
                if (i > 0 && a[i - 1] != '0')
                    dif = 1;
                else
                    dif = -9;
            } else
                dif = 0;
        }
        if (c < d) {
            mass[i] = c - d + 10;
            if (i > 0 && a[i - 1] != '0') {
                dif = 1;
            } else {
                if (i > 0 && a[i - 1] == '0') {
                    dif = -9;
                }
                if (i > 0 && a[i - 1] != '0') {
                    dif = 1;
                }
            }
        }
    }
    i = 0;
    while (mass[i] == 0 && i < len) {
        if (i != len - 1) flag++;
        i++;
    }

    return flag;
}

char *dif(char *new_a, char *new_b, char *a, char *b, int len) {
    char *result = malloc(len * sizeof(char));
    int c, d, dif = 0, def = len - strlen(new_a), res, i;
    for (i = len - 1; i >= 0; i--) {
        c = (int)new_a[i - def] - 48 - dif;
        d = (int)new_b[i - def] - 48;
        if (c >= d) {
            res = c - d;
            result[i] = (char)res + 48;
            if (c == 9 && dif == -9) {
                if (i > 0 && new_a[i - def - 1] != '0')
                    dif = 1;
                else
                    dif = -9;
            } else
                dif = 0;
        }
        if (c < d) {
            res = c - d + 10;
            result[i] = (char)c - d + 58;
            if (i > 0 && new_a[i - def - 1] != '0') {
                dif = 1;
            } else {
                if (i > 0 && new_a[i - def - 1] == '0') {
                    dif = -9;
                }
                if (i > 0 && new_a[i - def - 1] != '0') {
                    dif = 1;
                }
            }
        }
    }
    if (result[0] == '0') result[0] = '-';

    if (result[0] != '-')
        i = 0;
    else
        i = 1;
    int count = 0;
    while (result[i] == '0') {
        i++;
        if (result[i] == '-') {
            i++;
            count++;
            continue;
        }
        count++;
    }
    if (count > 0) {
        if (result[0] != '-') {
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
            result[i] = result[i + count];
            i++;
        }
    }
    result[len - count] = '\0';
    printf("result = %s", result);
    return result;
}
