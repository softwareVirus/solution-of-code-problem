/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteMiddle(struct ListNode* head){
    int size = 0;
    if(head == NULL || head->next == NULL) return NULL;
    struct ListNode *start = head,*tmp;
    while(start != NULL) {
        start = start->next;
        size++;
    }
    start = head;
    for(int i = 0; i < size/2-1; i++) {
        head = head->next;
    }
    tmp = head->next;
    head->next = head->next->next;
    free(tmp);
    return start;
}
