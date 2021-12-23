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
void preorder(struct TreeNode* root,int *size) {
    if(root != NULL) {
        *size = *size+1;
        preorder(root->left,size);
        preorder(root->right,size);
    }
}

void preorder_a(struct TreeNode* root,int *answer,int *size) {
    if(root != NULL) {
        answer[*size] = root->val;
        *size = *size+1;
        preorder_a(root->left,answer,size);
        preorder_a(root->right,answer,size);
    }
}


int* preorderTraversal(struct TreeNode* root, int* returnSize){
    int size = 0;
    preorder(root,&size);
    *returnSize = size;
    int *answer = (int *) malloc(sizeof(int)*size);
    size = 0;
    preorder_a(root,answer,&size);
    return answer;
}
