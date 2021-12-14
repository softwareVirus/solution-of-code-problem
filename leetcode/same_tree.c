/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


void in_order(struct TreeNode* p, struct TreeNode* q, bool *answer) {
    if(p != NULL && q != NULL) {
        if(p->val != q->val) *answer = false;
    } else if(p != NULL || q != NULL) {
        *answer = false;
    }
    if(*answer == true && p != NULL && q != NULL) {
        in_order(p->left,q->left,answer);
        in_order(p->right,q->right,answer);
    }
} 

bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    bool answer = true;
    in_order(p,q,&answer);
    return answer;
}
