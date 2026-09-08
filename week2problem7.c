#include <stdio.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

bool hasCycle(struct ListNode *head) {
    struct ListNode *slow = head;
    struct ListNode *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return true;
        }
    }

    return false;
}

int main() {
    struct ListNode a, b, c, d;

    a.val = 3;
    b.val = 2;
    c.val = 0;
    d.val = -4;

    a.next = &b;
    b.next = &c;
    c.next = &d;

    // Create cycle: -4 -> 2
    d.next = &b;

    if (hasCycle(&a)) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    return 0;
}
