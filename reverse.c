#include <stdlib.h>
#include <stdio.h>

struct listNode {
    int data;
    struct listNode *next;
};

struct listNode *createNode(int data) {
    struct listNode *p = (struct listNode *) malloc(sizeof(struct listNode));
    p->data = data;
    p->next = NULL;
    return p;
}

void deleteList(struct listNode *head) {
    if (head == NULL) return;
    deleteList(head->next);
    free(head);
}

struct listNode *list1() {
    struct listNode *head = NULL;
    struct listNode *p;
    for (int i = 0; i < 9; i++) {
        p = head;
        head = createNode(i);
        head->next = p;
    }
    return head;
}

struct listNode *reverse(struct listNode *head) {
    return NULL;
}

void displayList(struct listNode *head) {
    for (struct listNode *p = head; p != NULL; p = p->next) {
        printf("->%2d ", p->data);
    }
    printf("\n");
}

int main() {
    struct listNode *head = list1();
    printf("List 1:\n");
    displayList(head);
    head = reverse(head);
    printf("Reverse List 1:\n");
    displayList(head);

    deleteList(head);
}


