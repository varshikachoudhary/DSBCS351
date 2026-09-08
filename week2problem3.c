#include <stdio.h>
#include <stdlib.h>

// Definition of linked list node
struct ListNode {
    int val;
    struct ListNode *next;
};

// Function to reverse linked list
struct ListNode* reverseList(struct ListNode* head) {

    struct ListNode* prev = NULL;
    struct ListNode* current = head;
    struct ListNode* next = NULL;

    while (current != NULL) {

        // Store the next node
        next = current->next;

        // Reverse the link
        current->next = prev;

        // Move prev forward
        prev = current;

        // Move current forward
        current = next;
    }

    return prev;
}

int main() {

    // Create nodes
    struct ListNode* head = malloc(sizeof(struct ListNode));
    struct ListNode* second = malloc(sizeof(struct ListNode));
    struct ListNode* third = malloc(sizeof(struct ListNode));
    struct ListNode* fourth = malloc(sizeof(struct ListNode));
    struct ListNode* fifth = malloc(sizeof(struct ListNode));

    // Assign values
    head->val = 1;
    second->val = 2;
    third->val = 3;
    fourth->val = 4;
    fifth->val = 5;

    // Connect nodes
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = NULL;

    // Reverse the linked list
    head = reverseList(head);

    // Print reversed list
    struct ListNode* current = head;

    printf("Reversed Linked List: ");

    while (current != NULL) {
        printf("%d", current->val);

        if (current->next != NULL) {
            printf(" -> ");
        }

        current = current->next;
    }

    printf("\n");

    // Free memory
    current = head;

    while (current != NULL) {
        struct ListNode* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
