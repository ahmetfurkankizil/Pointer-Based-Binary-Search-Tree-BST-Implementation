/**
* Title: Binary Search Trees
* Author : Ahmet Furkan KIZIL
* ID: 22203112
* Section : 3
* Homework : 1
* Description : Binary Search Tree with required implementations
*/

#include "Node.h"

Node::Node(int key, Node *leftChild, Node *rightChild) {
    this->key = key;
    this->leftChild = leftChild;
    this->rightChild = rightChild;
}
