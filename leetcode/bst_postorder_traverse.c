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

void postorder(struct TreeNode* root,int *size) {
    if(root != NULL) {
        postorder(root->left,size);
        postorder(root->right,size);
        *size = *size+1;
    }
}

void postorder_a(struct TreeNode* root,int *answer,int *size) {
    if(root != NULL) {
        postorder_a(root->left,answer,size);
        postorder_a(root->right,answer,size);
        answer[*size] = root->val;
        *size = *size+1;
    }
}


int* postorderTraversal(struct TreeNode* root, int* returnSize){
    int size = 0;
    postorder(root,&size);
    *returnSize = size;
    int *answer = (int *) malloc(sizeof(int)*size);
    size = 0;
    postorder_a(root,answer,&size);
    return answer;
}
