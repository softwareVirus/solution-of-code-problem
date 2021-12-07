
struct ListNode* deleteDuplicates(struct ListNode* head){
    struct ListNode* answer = head;
    if(head == NULL || head->next == NULL) return head;
    while(head->next != NULL) {
        if(head->val == head->next->val) {
            while(head->next != NULL && head->val == head->next->val) {
                head->next = head->next->next; 
            }
        }
        head = head->next;
        if(head == NULL) break;
    }
    return answer;
}
