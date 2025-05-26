#ifndef PARSER_H
#define PARSER_H

#include <stdio.h>
#define MAX_LINE 100
#define MAX_LOG 100

typedef struct parser
{
    char message[1000];
    char level[20];
    char time[20];
} parser;

void parse_log(const char *filename, const char *level, int sort_by_time);
#endif