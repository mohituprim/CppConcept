#include <cstdlib>
#include "Tree.h"
#include <iostream>
#include <queue>
using namespace std;

Node* Tree::IntializeBinaryTree()
{
    //struct node* node = (struct node*)malloc(sizeof(struct node));
    Node *root = new Node(1);
    root->left             = new Node(2);
    root->right           = new Node(3);
    root->left->left     = new Node(4);
    root->left->right   = new Node(5); 
    return root;
}

/* Given a binary tree, print its nodes according to the
  "bottom-up" postorder traversal. */
void Tree::printPostorder(Node* node)
{
     if (node == NULL)
        return;
 
     // first recur on left subtree
     printPostorder(node->left);
 
     // then recur on right subtree
     printPostorder(node->right);
 
     // now deal with the node
     cout<<node->data;
}
 
/* Given a binary tree, print its nodes in inorder*/
void Tree::printInorder(Node* node)
{
     if (node == NULL)
          return;
 
     /* first recur on left child */
     printInorder(node->left);
 
     /* then print the data of node */
     cout<<node->data; 
 
     /* now recur on right child */
     printInorder(node->right);
}
 
/* Given a binary tree, print its nodes in preorder*/
void Tree::printPreorder(Node* node)
{
     if (node == NULL)
          return;
 
     /* first print data of node */
     cout<<node->data; 
 
     /* then recur on left sutree */
     printPreorder(node->left);  
 
     /* now recur on right subtree */
     printPreorder(node->right);
}

int Tree::Height(Node* node)
{
    if(node==NULL)
        return 0;
    int rH = Height(node->right);
    int lH = Height(node->left);
    
    if(rH>lH)
        return rH+1;
    else
        return lH+1;
}

void Tree::printLevelOrderRecursive(Node* root)
{
    int height = Height(root);
    for(int i=1; i<height; i++)
    {
        printGivenLevel(root, i);
    }
}

void Tree::printGivenLevel(Node* root, int level)
{
    if(root==NULL)
        return;
    if(level==1)
        cout<<root->data;
    else
    {
        printGivenLevel(root->left, level-1);
        printGivenLevel(root->right, level-1);
    
    }
}

void Tree::printLevelOrderUsingQueue(Node *root)
{
    queue<Node*> q;
    
    Node* temp = root;
    while(temp)
    {
        cout<<temp->data;
        if(temp->left)
            q.push((temp->left));
        if(temp->right)
            q.push((temp->right));
        
        temp = q.front();
        q.pop();
    
    }
    
 }