#include "input.h"
#include <ctype.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int read_int(int *number)
{
    char tmp[MAX_INT_LEN];
    if (fgets(tmp, MAX_INT_LEN, stdin) == NULL)
        return -1;

    int len_tmp = strlen(tmp);
    if (tmp[len_tmp - 1] == '\n')
        tmp[--len_tmp] = '\0';
    else {
        while (getchar() != '\n')
            ;
        return -1;
    }

    if (len_tmp == 0)
        return -1;

    char *endptr;
    long tmp_l;
    tmp_l = strtol(tmp, &endptr, 10);
    if (*endptr != '\0')
        return -1;

    if (tmp_l >= INT_MAX)
        return -1;

    *number = tmp_l;
    return 0;
}

int read_long(long *number)
{
    char tmp[MAX_INT_LEN];
    if (fgets(tmp, MAX_INT_LEN, stdin) == NULL)
        return -1;

    int len_tmp = strlen(tmp);
    if (tmp[len_tmp - 1] == '\n')
        tmp[--len_tmp] = '\0';
    else {
        while (getchar() != '\n')
            ;
        return -1;
    }

    if (len_tmp == 0)
        return -1;

    char *endptr;
    long tmp_l;
    tmp_l = strtol(tmp, &endptr, 10);
    if (*endptr != '\0')
        return -1;

    *number = tmp_l;
    return 0;
}

int read_char(char *c)
{
    int rc;
    char tmp[MAX_STR_LEN];
    if ((rc = read_str(stdin, tmp, MAX_STR_LEN)) == 0)
        return rc;

    if (tmp[1] != '\0')
        return -1;

    *c = tmp[0];
    return 0;
}

int read_str(FILE *f, char *s, int max_len)
{
    char tmp[MAX_STR_LEN];
    if (fgets(tmp, MAX_STR_LEN, f) == NULL)
        return -1;

    int len_tmp = strlen(tmp);
    if (tmp[len_tmp - 1] == '\n')
        tmp[--len_tmp] = '\0';
    else {
        while (getchar() != '\n')
            ;
        return -1;
    }

    if (len_tmp + 1 > max_len)
        return -1;

    strcpy(s, tmp);
    return len_tmp;
}

int read_double(double *number)
{
    char tmp[MAX_INT_LEN];
    if (fgets(tmp, MAX_INT_LEN, stdin) == NULL)
        return -1;

    int len_tmp = strlen(tmp);
    if (tmp[len_tmp - 1] == '\n')
        tmp[--len_tmp] = '\0';
    else {
        while (getchar() != '\n')
            ;
        return -1;
    }

    if (len_tmp == 0)
        return -1;

    char *endptr;
    double tmp_d;
    tmp_d = strtod(tmp, &endptr);
    if (*endptr != '\0')
        return -1;

    *number = tmp_d;
    return 0;
}
