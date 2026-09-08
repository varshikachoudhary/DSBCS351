#include <stdio.h>
#include <stdlib.h>

// Definition of linked list node
struct ListNode {
    int val;
    struct ListNode *next;
};

// Function to remove elements
struct ListNode* removeElements(struct ListNode* head, int val) {

    // Remove nodes from the beginning
    while (head != NULL && head->val == val) {
        struct ListNode* temp = head;
        head = head->next;
        free(temp);
    }

    // Remove nodes from the rest of the list
    struct ListNode* current = head;

    while (current != NULL && current->next != NULL) {

        if (current->next->val == val) {
            struct ListNode* temp = current->next;
            current->next = current->next->next;
            free(temp);
        }
        else {
            current = current->next;
        }
    }

    return head;
}

int main() {

    // Create nodes
    struct ListNode* head = malloc(sizeof(struct ListNode));
    struct ListNode* second = malloc(sizeof(struct ListNode));
    struct ListNode* third = malloc(sizeof(struct ListNode));
    struct ListNode* fourth = malloc(sizeof(struct ListNode));
    struct ListNode* fifth = malloc(sizeof(struct ListNode));
    struct ListNode* sixth = malloc(sizeof(struct ListNode));
    struct ListNode* seventh = malloc(sizeof(struct ListNode));

    // Assign values
    head->val = 1;
    second->val = 2;
    third->val = 6;
    fourth->val = 3;
    fifth->val = 4;
    sixth->val = 5;
    seventh->val = 6;

    // Connect nodes
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;
    seventh->next = NULL;

    int val = 6;

    // Remove elements
    head = removeElements(head, val);

    // Print linked list
    struct ListNode* current = head;

    printf("Linked List: ");

    while (current != NULL) {
        printf("%d", current->val);

        if (current->next != NULL) {
            printf(" -> ");
        }

        current = current->next;
    }

    printf("\n");

    // Free remaining nodes
    current = head;

    while (current != NULL) {
        struct ListNode* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
