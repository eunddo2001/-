#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

typedef struct TreeNode{
    int key;
    struct TreeNode *left, *right;
} TreeNode;

TreeNode* new_node(int item){
    TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
    temp->key=item;
    temp->left = NULL;
    temp->right=NULL;
    return temp;
}

TreeNode* insert_node(TreeNode **node, int key){
    if(node ==NULL)
        node = new_node(key);
    
    if(key<node->key)
        (*node)->left = insert_node((*node)->left, key);
    
    else if(key>(*node)->key)
        (*node)->right = insert_node((*node)->right, key);

    return node;
}

void inorder(FILE *stream, TreeNode *root){
    if(root){
        inorder(stream, root->left);
        printf("stream_int : %p\n", stream);
        fprintf(stream, "%d", root->key);
        inorder(stream, root->right);
    }
}

void preorder(FILE *stream, TreeNode *root){
    printf("stream : %p", stream);
    if(root){
        fprintf(stream, "%d", root->key);
        preorder(stream, root->left);
        preorder(stream, root->right);
    }
}

int main(void)
{
    FILE *fp = fopen("AVL.in","r");
    FILE *fout = fopen("AVL.out","w");

    char op[100];
    int input;
    TreeNode *root=NULL;

    while(fscanf(fp, "%s%d", op, &input) != EOF){
        printf("stream : %p\n", fout);
        fprintf(fout, "input: %d", input);
        insert_node(&root, input);
        inorder(fout, root);
        //preorder(fout, root);
        fprintf(fout, "\n");
        fprintf(fout, "BN");
        fprintf(fout, "\n");
        fprintf(fout, "\n");
    }
    
    fclose(fp);
    fclose(fout);
    return 0;
}