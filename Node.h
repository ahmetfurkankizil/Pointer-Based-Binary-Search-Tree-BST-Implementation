/**
* Title: Binary Search Trees
* Author : Ahmet Furkan KIZIL
* ID: 22203112
* Section : 3
* Homework : 1
* Description : Binary Search Tree with required implementations
*/

#ifndef CS202HW1_NODE_H
#define CS202HW1_NODE_H


class Node {
public:
    int key;
    Node *leftChild;
    Node *rightChild;
    Node(int key, Node *leftChild, Node *rightChild);
};


#endif //CS202HW1_NODE_H
