#ifndef HEADER_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *input();
int check_input(char *a, char *b);
char *sum(char *new_a, char *new_b, char *a, char *b, int len);
char *create_new(char *b, int len);
int test_calc_sum(char *a, char *b, int len);
int test_calc_dif(char *a, char *b, int len);
void result_sum(char *a, char *b);
void result_diff(char *a, char *b);
char *dif (char *new_a, char *new_b, char *a, char *b, int len);

#endif  //  HEADER_H_