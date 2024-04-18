#include "header.h"

int main() {
    printf("Put first number: ");
    char *a = input();
    printf("Put second number: ");
    char *b = input();
    char sign;
    printf("Put sign: ");
    scanf("%c", &sign);
    char **terms;
    char *res;
    char *new_a, *new_b, *test_a, *test_b, *result;
    int len_a, len_b, len;
    if (a && b) {
        clean(a);
        clean(b);
        printf("%s", a);
        if (check_input(a, b) == 0 /*&& (sign == '+' || sign == '-' || sign == '*' || sign == '/')*/) {
            switch (sign) {
                case '+':
                    if ((a[0] == '-' && b[0] == '-') || (a[0] != '-' && b[0] != '-'))
                        res = result_sum(a, b);
                    else if (a[0] == '-' && b[0] != '-')
                        result_diff(b, a);
                    else
                        result_diff(a, b);
                    printf("Result = %s", res);
                    break;
                case '-':
                    if ((a[0] == '-' && b[0] != '-'))
                        res = result_sum(a, b);
                    else if ((a[0] != '-' && b[0] == '-'))
                        res = result_sum(a, b);
                    else if ((a[0] == '-' && b[0] == '-'))
                        result_diff(b, a);
                    else if ((a[0] != '-' && b[0] != '-'))
                        result_diff(a, b);
                    break;
                case '*':
                    // for (int i = 0; i < strlen(a) * 2 + 1; i++) {
                    //     printf("%s\n", terms[i]);
                    // }
                    len_a = strlen(a), len_b = strlen(b), len = 0;
                    if (len_a > len_b)
                        len = 2 * len_a + 3;
                    else
                        len = 2 * len_b + 3;
                    terms = malloc(len * sizeof(char *));
                    for (int i = 0; i < len; i++) {
                        terms[i] = malloc(len * sizeof(char));
                    }
                    result_product(a, b, terms);
                    for (int i = 0; i < len; i++) {
                        printf("%s\n", terms[i]);
                    }
                    char *sum = malloc(sizeof(char) * len);
                    sum = terms[0];
                    for (int i = 1; i < len; i++) {
                        sum = result_sum(sum, terms[i]);
                    }
                    int len_sum = strlen(sum);
                    // printf("sum = %s\n", sum);
                    if ((a[0] == '-' && b[0] != '-') || (b[0] == '-' && a[0] != '-')) {
                        len_sum++;
                        for (int i = strlen(sum); i >= 1; i--) {
                            sum[i] = sum[i - 1];
                            // printf("sum[%d] = %c\n", i, sum[i]);
                        }
                        sum[0] = '-';
                    }
                    printf("result = %s", sum);
                    break;
                default:
                    printf("n/a");
                    break;
            }
        } else
            printf("n/a");
        free(a);
        free(b);
    }
    return 0;
}
