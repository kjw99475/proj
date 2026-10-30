#include <stdio.h>
#include <stdlib.h>
 
void alloc_it(int **pp) {
    *pp = malloc(sizeof(int));   /* 호출한 쪽의 포인터 자체를 바꿈 */
    **pp = 42;
}
 
int add(int a, int b) { return a + b; }
int mul(int a, int b) { return a * b; }
 
int main(void) {
    int *p = NULL;
    alloc_it(&p);
    printf("*p = %d\n", *p);
    free(p);
 
    int (*ops[2])(int, int) = { add, mul };
    printf("add=%d mul=%d\n", ops[0](3, 4), ops[1](3, 4));
    return 0;
}

