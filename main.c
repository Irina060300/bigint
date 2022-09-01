#include "header.h"

int main() {
    printf("Put first number: ");
    char *a = input();
    printf("Put second number: ");
    char *b = input();
    char sign;
    printf("Put sign: ");
    scanf("%c", &sign);
    if (a && b) {
        clean(a);
        clean(b);
        // printf("%s", a);
        if (check_input(a, b) == 0 && (sign == '+' || sign == '-' || sign == '*' || sign == '/')) {
            if (sign == '+') {
                if ((a[0] == '-' && b[0] == '-') || (a[0] != '-' && b[0] != '-'))
                    result_sum(a, b);
                else if (a[0] == '-' && b[0] != '-')
                    result_diff(b, a);
                else
                    result_diff(a, b);
            }
            if (sign == '-') {
                if ((a[0] == '-' && b[0] != '-'))
                    result_sum(a, b);
                else if ((a[0] != '-' && b[0] == '-'))
                    result_sum(a, b);
                else if ((a[0] == '-' && b[0] == '-'))
                    result_diff(b, a);
                else if ((a[0] != '-' && b[0] != '-'))
                    result_diff(a, b);
            }
            if (sign == '*') {
            }
        } else
            printf("n/a");
        free(a);
        free(b);
    }
    return 0;
}

