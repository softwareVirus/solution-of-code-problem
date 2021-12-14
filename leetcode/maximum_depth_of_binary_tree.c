/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void dft(struct TreeNode* root,int level,int *max) {
    if(root != NULL) {
        level++;
        dft(root->left,level,max);
        if(level > *max) {
            *max = level;
        }
        dft(root->right,level,max);
        level--;
    }
}

int maxDepth(struct TreeNode* root){
    int max = 0;
    dft(root,0,&max);
    return max;
}
