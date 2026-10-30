#include <stdio.h>
#include <errno.h>
 
int main(void) {
    FILE *fp = fopen("config.txt", "r");
    if (fp == NULL) {
        perror("fopen config.txt");
        return 1;
    }
    char line[128];
    int n = 0;
    while (fgets(line, sizeof(line), fp) != NULL) {
        n++;
        printf("%d: %s", n, line);
    }
    fclose(fp);
 
    FILE *log = fopen("run.log", "a");
    if (log == NULL) { perror("fopen run.log"); return 1; }
    fprintf(log, "read %d lines\n", n);
    fclose(log);
    return 0;
}

