/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    int size = 0;
    struct ListNode* begin = head;
    while(head != NULL) {
        size++;
        head = head->next;
    }
    head = begin;
    if(size-n == 0) {
        begin = begin->next;
        return begin;
    }
    for(int i = 1; i < size-n; i++) {
        head = head->next;
    }
    if(size > 1) head->next = head->next->next;
    else return NULL;
    return begin;
}
