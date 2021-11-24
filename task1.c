#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct NODE_s *NODE;

typedef struct NODE_s{
    NODE left;
    NODE right;
    int key;
    void *data;
} NODE_t[1],*NODE;

typedef struct{
    NODE root;
} BST_t[1],*BST;

NODE bst_node_init(int key,void *data) {
    NODE node = (NODE) malloc(sizeof(NODE_t));
    node->left = NULL;
    node->right = NULL;
    node->key = key;
    node->data = data;
    return node;
}

BST bst_tree_init() {
    BST tree = (BST) malloc(sizeof(BST_t));
    tree->root= NULL;
    return tree;
}

NODE bst_node_insert_recursive(NODE node,int key, void *data) {
    if(node != NULL) {
        if(node->key > key) {
            node->left = bst_node_insert_recursive(node->left,key,data);
        } else if(node->key < key) {
            node->right = bst_node_insert_recursive(node->right,key,data);
        } else {
            printf("Duplicated key !! \n");
        }
    } else {
        node = bst_node_init(key,data);
    }
    return node;
} 

void bst_node_insert(BST tree,int key,void *data) {
    if(tree == NULL) {
        printf("tree is not initialized!!\n");
    } else {
        if(tree->root == NULL) {
            tree->root = bst_node_init(key,data);
        } else {
            tree->root = bst_node_insert_recursive(tree->root,key,data);
        }
    }
} 

void print_space(int level) {
    for(int i = 0; i < level; i++) {
        printf("  ");
    }
}

void print_horizontally(NODE node,int level) {
    if(node != NULL) {
        level++;
        print_horizontally(node->right,level);
        print_space(level);
        printf("%d\n",node->key);
        print_horizontally(node->left,level);
        level--;
    }
} 


void backbone_with_left_rotation(BST tree, NODE gparent,NODE parent,int *size) {
    if(parent != NULL) {
        printf("*****************************************************\n");
        printf("parent = %d\n",parent->key);
        print_horizontally(tree->root,0);
        
        NODE child = parent->right;
        if(child != NULL) { 
            
            NODE keep = child->left;
            child->left = parent;
            parent->right = keep;
            gparent->left = child;
            backbone_with_left_rotation(tree,gparent,child,size);
        } else {
            *size = *size + 1;
            backbone_with_left_rotation(tree,gparent->left,parent->left,size);
        }
    }
}

int main() {
    BST tree = bst_tree_init();
    int array_keep[100];
    srand(time(NULL));
    for(int i = 0; i < 20; i++) {
        int random = rand() % 100;
        while(array_keep[random] != 0) {
            random = rand() % 100;
        }
        array_keep[random]++;
        bst_node_insert(tree,random,NULL);
    }
    int size = 0;
    backbone_with_left_rotation(tree,(NODE)tree,tree->root,&size);
    printf("tree size = %d\n",size);
}