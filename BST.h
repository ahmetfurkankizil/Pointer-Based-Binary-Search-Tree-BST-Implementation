/**
* Title: Binary Search Trees
* Author : Ahmet Furkan KIZIL
* ID: 22203112
* Section : 3
* Homework : 1
* Description : Binary Search Tree with required implementations
*/

#ifndef CS202HW1_BST_H
#define CS202HW1_BST_H
#include <iostream>
using namespace std;
#include "Node.h"

class BST {
private:
    Node *root;
    void insertKeyMain(int key, Node *&root);
    void insertKeyMainForConstructor(int key, Node *&root);
    void deleteKeyMain(int key, Node *&root);
    void destroyTree(Node* node);
    void deleteNode(Node *&nodeToBeDeleted);
    void process(Node *&nodeToBeDeleted, int &temp);
    void displayInorderRecursively(Node* currentNode);
    void maximumSumPath(Node* node, int sum, int* path, int pathLength, int& maxSum, int*& maxPath, int& maxPathLength);
    void searchSmallerPath(Node *currentNode, int A);
    void searchHigherPath(Node *currentNode, int A, int size);
    void searchMoreSmallerPath(Node *currentNode, int A, int B);
    void searchMoreHigherPath(Node *currentNode, int A, int B);
    int getSizeOfArray(Node *currentNode, int A);
    void searchHigherPathSpecial(Node *currentNode, int A, int size);
    bool exists(int A);
    int findMaxValue(Node* currentNode);


public:
    BST(int keys[], int size);
    ~BST();
    void insertKey(int key);
    void deleteKey(int key);
    void displayInorder();
    void findFullBTLevel();
    void lowestCommonAncestor(int A, int B);
    void maximumSumPath();
    void maximumWidth();
    void pathFromAtoB(int A, int B);
    int getHeightRecursively(Node* currentNode);           //Change this afterward
    int getHeight();           //Change this afterward
};

#endif //CS202HW1_BST_H
