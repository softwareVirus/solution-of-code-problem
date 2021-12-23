/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void inorder(struct TreeNode* root,int *size) {
    if(root != NULL) {
        inorder(root->left,size);
        *size = *size+1;
        inorder(root->right,size);
    }
}

void inorder_a(struct TreeNode* root,int *answer,int *size) {
    if(root != NULL) {
        inorder_a(root->left,answer,size);
        answer[*size] = root->val;
        *size = *size+1;
        inorder_a(root->right,answer,size);
    }
}


int* inorderTraversal(struct TreeNode* root, int* returnSize){
    int size = 0;
    inorder(root,&size);
    *returnSize = size;
    int *answer = (int *) malloc(sizeof(int)*size);
    size = 0;
    inorder_a(root,answer,&size);
    return answer;
}
