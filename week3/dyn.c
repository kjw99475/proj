#include <stdio.h>
#include <stdlib.h>
 
int main(void) {
    int n = 4;
    int *arr = malloc(sizeof(int) * n);
    if (arr == NULL) { perror("malloc"); return 1; }
    for (int i = 0; i < n; i++) arr[i] = i * 10;
 
    int *tmp = realloc(arr, sizeof(int) * 8);
    if (tmp == NULL) { free(arr); return 1; }
    arr = tmp;
    arr[7] = 70;
    printf("arr[3]=%d arr[7]=%d\n", arr[3], arr[7]);
 
    free(arr);
    arr = NULL;        /* 댕글링 포인터 예방 */
    return 0;
}

