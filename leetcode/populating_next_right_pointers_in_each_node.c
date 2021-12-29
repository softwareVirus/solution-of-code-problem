/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *left;
 *     struct Node *right;
 *     struct Node *next;
 * };
 */


void cut_off_right_sides(struct Node *root) {
    if(root != NULL) {
        root->next = NULL;
        cut_off_right_sides(root->right);
    }
}

// **I can't implement a queue data structer. if it is used, memory usage will decrease.
struct Node* connect(struct Node* root) {
    if(root == NULL) return root;
	struct Node **queue = (struct Node **) malloc(sizeof(struct Node *));
    queue[0] = root;
    int head = 0;
    int tail = 0;
    int size = 1;
    struct Node *tmp = NULL;
    while(1){
        if(tmp == NULL) {
            tmp = queue[head];
            head++;
            if(tmp->left != NULL) {
                queue = (struct Node **) realloc(queue,sizeof(struct Node *)*(size+2));
                tail++;
                queue[tail] = tmp->left; 
                tail++;
                queue[tail] = tmp->right;
                size+=2;
            } else {
                break;
            }
            
        } else {
            tmp->next = queue[head];
            head++;
            tmp = tmp->next;
            if(tmp->left != NULL) {
                queue = (struct Node **) realloc(queue,sizeof(struct Node *)*(size+2));
                tail++;
                queue[tail] = tmp->left; 
                tail++;
                queue[tail] = tmp->right;
                size+=2;
            } else {
                break;
            }
        }
    } 
    while(head <= tail) {
        tmp->next = queue[head]; 
        tmp = tmp->next;
        head++;
    }
    cut_off_right_sides(root);
    return root;
}
