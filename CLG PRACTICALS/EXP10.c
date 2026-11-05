#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int x)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int x)
{
    if(root==NULL) return createNode(x);

    if(x<root->data) root->left = insert(root->left,x);
    else if(x>root->data) root->right = insert(root->right,x);

    return root;
}

struct Node* search(struct Node* root,int x)
{
    if(root==NULL||root->data==x) return root;

    if(x<root->data) return search(root->left,x);

    return search(root->right,x);
}

int main()
{
    struct Node* root = NULL;
    struct Node* res;
    int x;

    root = insert(root,50);
    insert(root,30);
    insert(root,70);
    insert(root,20);
    insert(root,40);
    insert(root,60);
    insert(root,80);

    printf("Enter Element To Search: ");
    scanf("%d",&x);

    res = search(root, x);
    if(res!=NULL) printf("Element Found\n");
    else printf("Element Not Found\n");

}