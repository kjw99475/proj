#include <stdio.h>
 
int g_total = 0;          /* 전역: 자동으로 0 */
 
static int helper(void) { /* 이 파일 안에서만 사용 가능 */
    static int count = 0; /* 수명은 프로그램 전체 */
    int local = 0;        /* 호출할 때마다 새로 생김 */
    count++;
    local++;
    printf("count=%d local=%d\n", count, local);
    return count;
}
 
int main(void) {
    for (int i = 0; i < 3; i++) g_total = helper();
    printf("g_total=%d\n", g_total);
    return 0;
}

