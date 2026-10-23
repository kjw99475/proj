#include <stdio.h>
#include "mystr.h"

int main(void) {
    const char *src = "router";
    char buf[32];

    printf("len  = %zu\n", my_strlen(src));
    my_strcpy(buf, src);
    printf("copy = %s\n", buf);
    printf("cmp(same) = %d\n", my_strcmp(src, buf));
    printf("cmp(router, routes) = %d\n", my_strcmp("router", "routes"));
    return 0;
}
