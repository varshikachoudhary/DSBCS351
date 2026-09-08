#include <stdio.h>
#include <stdlib.h>

// Definition of linked list node
struct ListNode {
    int val;
    struct ListNode *next;
};

// Function to find middle node
struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
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

    // Find middle
    struct ListNode* middle = middleNode(head);

    printf("Middle node: %d\n", middle->val);

    // Free memory
    free(head);
    free(second);
    free(third);
    free(fourth);
    free(fifth);

    return 0;
}
