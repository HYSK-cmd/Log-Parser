#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "parser.h"
// Compares log entries by time
int compare_time(const void *a, const void *b){
    const parser *log1 = (const parser *) a;
    const parser *log2 = (const parser *) b;
    return strcmp(log1->time, log2->time);
}

void parse_log(const char *filename, const char *level, int sort_by_time){
    // Open the log file for reading
    FILE *log_file = fopen(filename, "r");
    if(!log_file){
        perror("fopen failed\n");
        return;
    }

    parser logs[MAX_LOG];   // Array to store parsed log entries
    int count = 0;          // Total number of logs read
    char line[MAX_LINE];    

    int INFO_cnt = 0, ERROR_cnt = 0, WARNING_cnt = 0;   // Counters for each log level

    while(fgets(line, sizeof(line), log_file) != NULL){
        if (count >= MAX_LINE) break;
        sscanf(line, "[%[^]]] [%[^]]] %[^\n]", 
               logs[count].time, 
               logs[count].level, 
               logs[count].message);
        // Increment the number of each level
        if (strcmp(logs[count].level, "INFO") == 0) INFO_cnt++;
        else if (strcmp(logs[count].level, "ERROR") == 0) ERROR_cnt++;
        else if (strcmp(logs[count].level, "WARNING") == 0) WARNING_cnt++;
        count++;
    }
    fclose(log_file);
    // Sort logs by time if flag is enabled
    if(sort_by_time == 1) qsort(logs, count, sizeof(parser), compare_time);
    
    // Print each log entry (apply level filter if needed)
    for(int i = 0; i < count; i++){
        if(level && strcmp(logs[i].level, level) != 0) continue;
        printf("[%s] [%s] %s\n", logs[i].time, logs[i].level, logs[i].message);
    }
    // Print summary of log level counts
    printf("\n[INFO]: %d\t[ERROR]: %d\t[WARNING]: %d\n", INFO_cnt, ERROR_cnt, WARNING_cnt);

}