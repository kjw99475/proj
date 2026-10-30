#include <stdio.h>
#include <stdlib.h>

int main() {
    int *n = malloc(sizeof(int) * 4);

    n[0] = 10;
    n[1] = 20;
    n[2] = 30;
    n[3] = 40;

    printf("%d\n", n[0]);

    return 0;
}
