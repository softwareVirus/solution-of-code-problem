/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* middleNode(struct ListNode* head){
    int size = 0;
    struct ListNode *start = head;
    while(start != NULL) {
        start = start->next;
        size++;
    }
    for(int i = 0; i < size/2; i++) {
        head = head->next;
    }
    return head;
}
