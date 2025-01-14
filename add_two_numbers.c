#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *current = dummy;
    int carry = 0;
    
    while (l1 != NULL || l2 != NULL || carry) {
        int sum = carry;
        
        if (l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;
        }
        
        if (l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;
        }
        
        carry = sum / 10;
        current->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        current = current->next;
        current->val = sum % 10;
    }
    
    return dummy->next;
}

int main() {
    // Example: Add two linked lists
    // 342 + 465 = 807
    struct ListNode l1 = {2, NULL};
    struct ListNode l2 = {4, NULL};
    struct ListNode l3 = {3, NULL};
    l1.next = &l2;
    l2.next = &l3;

    struct ListNode r1 = {5, NULL};
    struct ListNode r2 = {6, NULL};
    struct ListNode r3 = {4, NULL};
    r1.next = &r2;
    r2.next = &r3;
    
    struct ListNode *result = addTwoNumbers(&l1, &r1);
    while (result) {
        printf("%d ", result->val);
        result = result->next;
    }
    printf("\n");
    return 0;
}
