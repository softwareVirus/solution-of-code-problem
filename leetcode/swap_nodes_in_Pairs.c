/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* swapPairs(struct ListNode* head){
    if(head == NULL) return head;
    if(head->next == NULL) return head;
    struct ListNode *answer = head->next,*before = NULL,*second = NULL;
    while(head != NULL) {
        if(head->next == NULL) break;
        second = head->next->next; 
        if(before != NULL) {
            before->next = head->next;
        }
        head->next->next = head;
        head->next = second;
        before = head;
        head = second;
    }
    return answer;
}
