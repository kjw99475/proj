#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
 
typedef struct node {
    uint8_t mac[6];
    int     port;
    struct node *next;
} node_t;
 
int add_entry(node_t **head, const uint8_t *mac, int port) {
    node_t *n = malloc(sizeof(node_t));
    if (n == NULL) return -1;
    memcpy(n->mac, mac, 6);
    n->port = port;
    n->next = *head;      /* 먼저 연결 */
    *head = n;            /* 그다음 머리 교체 */
    return 0;
}
 
node_t *find_entry(node_t *head, const uint8_t *mac) {
    for (node_t *c = head; c != NULL; c = c->next)
        if (memcmp(c->mac, mac, 6) == 0) return c;
    return NULL;
}
 
int del_entry(node_t **head, const uint8_t *mac) {
    node_t **pp = head;
    while (*pp != NULL) {
        if (memcmp((*pp)->mac, mac, 6) == 0) {
            node_t *dead = *pp;
            *pp = dead->next;   /* 먼저 이어 준 뒤 */
            free(dead);         /* 해제 */
            return 0;
        }
        pp = &(*pp)->next;
    }
    return -1;
}

int main(void) {
    node_t *head = NULL;

    uint8_t mac1[6] = {0x00, 0x1A, 0x2B, 0x3C, 0x4D, 0x5E};
    uint8_t mac2[6] = {0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF};
    uint8_t mac3[6] = {0x11, 0x22, 0x33, 0x44, 0x55, 0x66};

    // 항목 3개 추가
    add_entry(&head, mac1, 1);
    add_entry(&head, mac2, 2);
    add_entry(&head, mac3, 3);

    // 첫 번째 항목 조회
    node_t *found = find_entry(head, mac1);

    if (found != NULL)
        printf("Found! port = %d\n", found->port);

    // 첫 번째 항목 삭제
    del_entry(&head, mac1);

    // 삭제한 항목 다시 조회
    found = find_entry(head, mac1);

    if (found != NULL)
        printf("Found! port = %d\n", found->port);
    else
        printf("Entry not found\n");

    // 남은 항목도 정리
    del_entry(&head, mac2);
    del_entry(&head, mac3);

    return 0;
}
