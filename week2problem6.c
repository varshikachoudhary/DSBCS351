#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

void deleteNode(struct ListNode* node) {
    node->val = node->next->val;
    node->next = node->next->next;
}

int main() {
    // Create nodes: 4 -> 5 -> 1 -> 9
    struct ListNode *head = malloc(sizeof(struct ListNode));
    struct ListNode *second = malloc(sizeof(struct ListNode));
    struct ListNode *third = malloc(sizeof(struct ListNode));
    struct ListNode *fourth = malloc(sizeof(struct ListNode));

    head->val = 4;
    second->val = 5;
    third->val = 1;
    fourth->val = 9;

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = NULL;

    // Delete node with value 5
    deleteNode(second);

    // Print list
    struct ListNode *current = head;

    printf("Linked List: ");

    while (current != NULL) {
        printf("%d", current->val);

        if (current->next != NULL)
            printf(" -> ");

        current = current->next;
    }

    printf("\n");

    return 0;
}
