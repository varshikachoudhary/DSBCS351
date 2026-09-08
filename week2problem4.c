#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* list1,
                               struct ListNode* list2) {
    struct ListNode dummy;
    struct ListNode *current = &dummy;

    dummy.next = NULL;

    while (list1 != NULL && list2 != NULL) {
        if (list1->val <= list2->val) {
            current->next = list1;
            list1 = list1->next;
        } else {
            current->next = list2;
            list2 = list2->next;
        }

        current = current->next;
    }

    if (list1 != NULL)
        current->next = list1;
    else
        current->next = list2;

    return dummy.next;
}

int main() {
    // List 1: 1 -> 2 -> 4
    struct ListNode *list1 = malloc(sizeof(struct ListNode));
    struct ListNode *l1_2 = malloc(sizeof(struct ListNode));
    struct ListNode *l1_3 = malloc(sizeof(struct ListNode));

    list1->val = 1;
    l1_2->val = 2;
    l1_3->val = 4;

    list1->next = l1_2;
    l1_2->next = l1_3;
    l1_3->next = NULL;

    // List 2: 1 -> 3 -> 4
    struct ListNode *list2 = malloc(sizeof(struct ListNode));
    struct ListNode *l2_2 = malloc(sizeof(struct ListNode));
    struct ListNode *l2_3 = malloc(sizeof(struct ListNode));

    list2->val = 1;
    l2_2->val = 3;
    l2_3->val = 4;

    list2->next = l2_2;
    l2_2->next = l2_3;
    l2_3->next = NULL;

    // Merge
    struct ListNode *result = mergeTwoLists(list1, list2);

    // Print result
    printf("Merged List: ");

    while (result != NULL) {
        printf("%d", result->val);

        if (result->next != NULL)
            printf(" -> ");

        result = result->next;
    }

    printf("\n");

    return 0;
}
