/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


void in_order(struct TreeNode* root,int k,int *step,int *answer) {
    if(root != NULL && *answer == -1) {
        in_order(root->left,k,step,answer);
        *step = *step+1;
        if(*step == k) {
            *answer = root->val;
        }
        in_order(root->right,k,step,answer);
    }
}

int kthSmallest(struct TreeNode* root, int k){
    int step = 0;
    int answer = -1;
    in_order(root,k,&step,&answer);
    return answer;
}
