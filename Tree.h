/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tree.h
 * Author: mohituprim
 *
 * Created on 7 April, 2018, 6:47 PM
 */

#ifndef TREE_H
#define TREE_H
//Can declare struct also
//With struct, we can have constructor also
//new works with struct too
class Node 
{

  public:
    int data;
    Node *left;
    Node *right;
    Node(int item)
    {
        this->left=NULL;
        this->right = NULL;
        this->data = item;

    }
};

class Tree
{
public:
    Node* IntializeBinaryTree();
    void printPostorder(Node* node);
    void printInorder(Node* node);
    void printPreorder(Node* node);
    int Height(Node* node);
    void printLevelOrderRecursive(Node*);
    void printGivenLevel(Node*, int);
    void printLevelOrderUsingQueue(Node*);
};

#endif /* TREE_H */

