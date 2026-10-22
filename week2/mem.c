#include <stdio.h>
 
int g_init = 5;      /* 데이터 영역 */
int g_zero;          /* BSS 영역 */
 
int main(void) {
    int local = 1;   /* 스택 */
    printf("g_init addr = %p\n", (void *)&g_init);
    printf("g_zero addr = %p\n", (void *)&g_zero);
    printf("local  addr = %p\n", (void *)&local);
    return 0;
}
