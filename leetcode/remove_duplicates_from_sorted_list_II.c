/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* remove_dup(struct ListNode* head) {
    
    while(head->val == head->next->val) {
        head = head->next;
         if(head->next == NULL) break;
    }
    head = head->next;
    if(head != NULL) {
        if(head->next != NULL) {
            if(head->val == head->next->val) head = remove_dup(head);
        }
    }
    return head;
}

struct ListNode *node_init(int val) {
    struct ListNode* node = (struct ListNode*) malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
} 

struct ListNode* push(struct ListNode* answer,struct ListNode* head) {
    struct ListNode *node = node_init(head->val);
    answer->next = node;
    return answer->next;
    
}
struct ListNode* deleteDuplicates(struct ListNode* head){
    struct ListNode* answer = NULL,*returned = NULL;
    while(head != NULL) {
        if(head->next != NULL) {
            if(head->val == head->next->val) {
                head = remove_dup(head);
                if(head != NULL) {
                    if(answer == NULL) {
                        answer = node_init(head->val);
                        returned = answer;
                    } else {
                        answer = push(answer,head);
                    }
                }
            } else {
                if(answer == NULL) {
                    answer = node_init(head->val);
                    returned = answer;
                } else {
                    answer = push(answer,head);
                }
            } 
        } else {
            if(answer == NULL) {
               answer = node_init(head->val);
               returned = answer;
            } else {
                answer = push(answer,head);
            }
        }
        if(head != NULL)head = head->next;
    }
    return returned;
}
