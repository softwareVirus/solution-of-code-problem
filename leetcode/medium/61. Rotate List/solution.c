/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* rotateRight(struct ListNode* head, int k){
    if(head == NULL) return NULL;
    int size = 0;
    struct ListNode* start = head,*keep,*last;
    while(start != NULL) {
        start = start->next;
        size++;
    }
    k = k%size;
    if(k == 0) return head;
    start = head;
    last = head;
    while(last->next != NULL) {
        last = last->next;
    }
    for(int i = 0; i < size-k-1; i++) {
        start = start->next;
    }
    keep = start->next;
    last->next = head;
    start->next = NULL;
    return keep;
}
