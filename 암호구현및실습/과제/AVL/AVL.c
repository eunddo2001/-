#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#define max(a,b)  (((a) > (b)) ? (a) : (b))

int BN[100]={0};
int cnt;

typedef struct TreeNode{
    int key;
    int balance;
    struct TreeNode *left, *right;
} TreeNode;

TreeNode* new_node(int item){
    TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
    temp->key=item;
    temp->balance=0;
    temp->left = NULL;
    temp->right=NULL;
    return temp;
}

int get_height(TreeNode *node){
    int height=0;
    if(node!=NULL){
        height = 1+max(get_height(node->left), get_height(node->right));
    }
    return height;
}

int get_balance(TreeNode *node){
    if (node ==NULL)
        return 0;
    return get_height(node->left) - get_height(node->right);
}

TreeNode* insert_node(TreeNode **node, int key){
    if(*node ==NULL)
        (*node) = new_node(key);
    
    if(key<(*node)->key){
        (*node)->left = insert_node(&((*node)->left), key);
        (*node)->balance = get_balance(*node);
        if (((*node)->balance)<-1 || ((*node)->balance)>1){
            cnt++;
            printf("cnt is %d\n", cnt);
            BN[cnt]=(long int)((*node)->key);                
            printf("left %ld\n", (long int)((*node)->key));
        }
    }

    else if(key>(*node)->key){
        (*node)->right = insert_node(&((*node)->right), key);
        (*node)->balance = get_balance(*node);
        if (((*node)->balance)<-1 || ((*node)->balance)>1){
            cnt++;
            printf("cnt is %d\n", cnt);
            BN[cnt]=(long int)((*node)->key);
            printf("right %ld\n", (long int)((*node)->key));
        }
    }

    return *node;
}

void inorder(FILE *stream, TreeNode *root){
    if(root){
        inorder(stream, root->left);
        fprintf(stream, "%d ", root->key);
        inorder(stream, root->right);
    }
}

void preorder(FILE *stream, TreeNode *root){
    if(root){
        fprintf(stream, "%d ", root->key);
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
        fprintf(fout, "input: %d\n", input);
        printf("\ninput %d\n", input);
        insert_node(&root, input);

        fprintf(fout, "I ");
        inorder(fout, root);
        fprintf(fout, "\n");

        fprintf(fout, "P ");
        preorder(fout, root);
        fprintf(fout, "\n");

        fprintf(fout, "BN %d\n\n", BN[1]);
        cnt=0;
    }
    
    fclose(fp);
    fclose(fout);
    return 0;
}