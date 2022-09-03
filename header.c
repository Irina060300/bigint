#include "header.h"

char *result_sum(char *a, char *b) {
    // printf("a = %s, b = %s\n", a, b);
    char *result;
    char *new_a, *new_b;
    char *test_a, *test_b;
    int len_a = strlen(a);
    int len_b = strlen(b);
    int len = 0;
    if (len_a > len_b) {
        // test_a = create_new(a, len_a);
        // test_b = create_new(b, len_a);
        // if (test_calc_sum(test_a, test_b, len_a) == 1) {
            len = len_a + 1;
        // } else
            len = len_a + 10;
    }
    if (len_b >= len_a) {
        // if (a[0] == '-' && b[0] != '-') len_b++;
        // test_a = create_new(a, len_b);
        // test_b = create_new(b, len_b);
        // if (test_calc_sum(test_a, test_b, len_b) == 1) {
            len = len_b + 1;
        // } else
            len = len_b + 10;
    }
    new_a = malloc(len * sizeof(char));
    new_b = malloc(len * sizeof(char));
    new_a = create_new(a, len);
    new_b = create_new(b, len);
    result = sum(new_a, new_b, a, b, len);

    // free(test_a);
    // free(test_b);
    free(new_a);
    free(new_b);
    return result;
    // free(result);
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
        result = dif(test_a, test_b, a, b, len);
    } else if (len_b > len_a) {
        test_a = create_new(a, len_b + 1);
        test_b = create_new(b, len_b + 1);
        // len = len_b + 1 - test_calc_dif(test_b, test_a, len_b) + 1;
        result = dif(test_b, test_a, b, a, len_b + 1);

    } else if (len_b == len_a) {
        if (max_of_ab(a, b) == 0) {
            test_a = create_new(a, len_b);
            test_b = create_new(b, len_b);
            len = len_b - test_calc_dif(test_a, test_b, len_b);
            result = dif(test_a, test_b, a, b, len);
        } else {
            len = len_b + 1;
            test_a = create_new(a, len);
            test_b = create_new(b, len);
            // len = len_b - test_calc_dif(test_a, test_b, len);
            result = dif(test_b, test_a, b, a, len);
        }
    }
    printf("Result = %s", result);
    free(test_a);
    free(test_b);
    free(result);
}

char **result_product(char *a, char *b) {
    printf("shshsdfhsdh");
    char *result;
    char *new_a, *new_b;
    char *test_a, *test_b;
    char **terms;
    int len_a = strlen(a);
    int len_b = strlen(b);
    int len = 0;
    if (a[0] == '-' && b[0] != '-' || b[0] == '-' && a[0] != '-') {
        if (len_a > len_b) {
            len = len_a * 2 + 3;
        } else {
            len = len_b * 2 + 3;
        }

        new_a = create_new(a, len);
        new_b = create_new(b, len);
        printf("new_a = %s new_b = %s\n", new_a, new_b);
        terms = product(new_a, new_b, a, b, len);

    } else {
        if (len_a > len_b) {
            len = len_a * 2 + 3;
        } else {
            len = len_b * 2 + 3;
        }
        new_a = create_new(a, len);
        new_b = create_new(b, len);
        printf("new_a = %s new_b = %s\n", new_a, new_b);
        terms = product(new_a, new_b, a, b, len);
        // result = sum(terms[1], terms[2], a, b, len);
        // printf("%s", result);
    }
    return terms;
}

char **product(char *new_a, char *new_b, char *a, char *b, int len) {
    // int def = len - strlen(new_a);
    int i = 0, c = 0, d = 0, cel, move_left = 0, count;
    char **terms;
    terms = malloc(len * sizeof(char *));
    for (int i = 0; i < len; i++) {
        terms[i] = malloc(len * sizeof(char));
    }
    for (i = len - 1; i >= 0; i--) {
        d = (int)new_b[i] - 48;
        cel = 0;
        count = 0;
        for (int j = len - 1; j >= 0; j--) {
            if (count < move_left) {
                terms[i][j] = '0';
                count++;
            }
            c = (int)new_a[j] - 48;
            if (j - move_left >= 0) terms[i][j - move_left] = (char)(c * d + cel) % 10 + 48;
            cel = (c * d + cel) / 10;
        }
        move_left++;
    }
    // for (int i = 0; i < len; i++) {
    //     printf("%s\n", terms[i]);
    // }
    for (int i = len - 1; i >= 0; i--) {
        printf("i = %d, trems[i] = %s, pisdec\n", i, terms[i]);
        clean(terms[i]);
        printf("i = %d, trems[i] = %s, pisdec\n", i, terms[i]);
    }

    return terms;
    // for (int i = 0; i < len - 1; i++) {

    // }
    // printf("%s", result);
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
    clean(result);
    return result;
}
int max_of_ab(char *a, char *b) {
    int flag = 0;
    size_t i = 0;
    while (a[i] == b[i]) i++;
    if (i < strlen(a) && b[i] > a[i]) flag++;
    // printf("FLAG = %d", flag);
    return flag;
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

char *input() {
    char *b = NULL;
    ;
    char c = '\0';
    int i = 0;
    while (c != '\n') {
        c = getchar();
        b = realloc(b, i);
        b[i] = c;
        i++;
        // if (i > 2022) b[0] = 'a';
    }
    // printf("a%ca\n", b[i - 1]);
    b[i - 1] = '\0';
    return b;
}

// char *input() {
//     char *a = malloc(sizeof(char) * BUFFER_SIZE);
//     int len = BUFFER_SIZE;
//     char c = 0;
//     int i = 0;
//     while (c != '\n') {
//         c = (char) getchar();
//         if (i >= len) {
//             if (DEBUG) printf("REALLOC, old_size=%d, new_size=%d\n", len, BUFFER_SIZE * (i / BUFFER_SIZE + 1));
//             len = BUFFER_SIZE * (i / BUFFER_SIZE + 1);
//             a = realloc(a, len);
//         }
//         a[i] = c;
//         i++;
//     }
//     if (DEBUG) printf("REALLOC, old_size=%d, new_size=%d\n", len, i);
//     a = realloc(a, i);
//     a[i - 1] = '\0';
//     return a;
// }

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

        // printf("mass[%d] = %d, dif = %d\n", i, mass[i], dif);
    }
    i = 0;
    while (mass[i] == 0 && i < len) {
        if (i != len - 1) flag++;
        i++;
    }
    free(mass);
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
        // printf("result[%d] = %c\n", i, result[i]);
    }

    if (result[0] == '0' && len > 1) result[0] = '-';
    clean(result);
    // printf("result = %s", result);
    return result;
}

void clean(char *a) {
    size_t len = strlen(a);
    size_t i = 0;
    if (a[i] == '-') i = 1;
    int count = 0;
    while (a[i] == '0') {
        i++;
        count++;
    }
    if (count > 0) {
        if (a[0] != '-') {
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
            a[i] = a[i + count];
            i++;
        }
    }
    a[len - count] = '\0';
}
