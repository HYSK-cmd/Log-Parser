#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "parser.h"

int main(int argc, char* argv[]){
    const char *log_file = "sample.log";
    const char *level = NULL;
    int x = 0;
    int sort_by_time = 0;
    while(x < argc){
        if(strcmp(argv[x], "-f") == 0 && x + 1 < argc){
            log_file = argv[x + 1]; //e.g. -f <filename>
        }
        if(strcmp(argv[x], "-l") == 0 && x + 1 < argc){
            level = argv[x + 1];    //e.g. -l <level>
        }
        if(strcmp(argv[x], "-s") == 0){
            sort_by_time = 1;
        }
        x++;
    }
    parse_log(log_file, level, sort_by_time);
    return 0;
}