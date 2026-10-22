#include <stdio.h>
 
int add(int a, int b) { return a + b; }
 
void try_change(int x) { x = 999; }
 
int main(void) {
    int sum = 0;
    for (int i = 1; i <= 5; i++) {
        if (i % 2 == 0) continue;   /* 짝수는 건너뜀 */
        sum = add(sum, i);
    }
    printf("sum of odds = %d\n", sum);
 
    int v = 1;
    try_change(v);
    printf("v = %d\n", v);
    return 0;
}
