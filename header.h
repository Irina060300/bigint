#ifndef HEADER_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 10
#define DEBUG 1


char *input();
int check_input(char *a, char *b);
char *sum(char *new_a, char *new_b, char *a, char *b, int len);
char *create_new(char *b, int len);
int test_calc_sum(char *a, char *b, int len);
int test_calc_dif(char *a, char *b, int len);
char *result_sum(char *a, char *b);
void result_diff(char *a, char *b);
char ** result_product(char *a, char *b);
char **product(char *new_a, char *new_b, char *a, char *b, int len);
char *dif (char *new_a, char *new_b, char *a, char *b, int len);
void clean(char *a);
int max_of_ab(char *a, char *b);

#endif  //  HEADER_H_