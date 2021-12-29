/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int size (struct ListNode* tmp) {
    int s = 0;
    while(tmp != NULL) {
        s+=1;
        tmp = tmp->next;
    }
    return s;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int remainder = 0;
    struct ListNode* start = l2,*first,*second,*before;
    if(size(l1) > size(l2)) {
        first = l1;
        second = l2;
    } else {
        first = l2;
        second = l1;
    }
    start = first;
    while(first != NULL) {
        if(second != NULL) {
            int tmp = first->val;
            first->val = (first->val+second->val+remainder)%10;
            remainder = (tmp+second->val+remainder)/10;
        } else {
            int tmp = first->val;
            first->val = (first->val+remainder)%10;
            remainder = (tmp+remainder)/10;
        }
        before = first;
        first = first->next;
        if(second != NULL) second = second->next;
    }
    if(remainder != 0) {
        before->next = (struct ListNode*) malloc(sizeof(struct ListNode));
        before->next->next = NULL;
        before->next->val = remainder;
    }
    return start;
}
