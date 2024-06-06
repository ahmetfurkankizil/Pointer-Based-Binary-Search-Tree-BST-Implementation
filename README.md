# BST Project

## Project Title
**Pointer-Based Binary Search Tree (BST) Implementation in C++**

## Overview
This project implements a pointer-based Binary Search Tree (BST) in C++ with various functionalities such as insertion, deletion, and several tree-related operations. The project is structured with the interface and implementation separated into header (`BST.h`) and source (`BST.cpp`) files respectively.

## Features
1. **Insertion of Keys**: Insert integer keys into the BST.
2. **Deletion of Keys**: Delete integer keys from the BST.
3. **Inorder Traversal**: Display an inorder traversal of the BST.
4. **Full Binary Tree Level**: Find and display the maximum level at which the tree is a full binary tree.
5. **Lowest Common Ancestor**: Find and display the lowest common ancestor of two given keys.
6. **Maximum Sum Path**: Find and display the path from root to a leaf node which has the maximum sum of the keys.
7. **Maximum Width**: Find and display the level with the maximum number of nodes and its keys.
8. **Path Between Nodes**: Find and display the path between two given keys.

## Files
- `BST.h`: Header file containing the class definition and member function declarations.
- `BST.cpp`: Source file containing the implementation of the BST class and its member functions.

## Class Interface
### BST.h
```cpp
#ifndef BST_H
#define BST_H

#include <vector>

class BST {
public:
    BST(const std::vector<int>& keys); // Constructor

    void insertKey(int key);           // Insert a key into the BST
    void deleteKey(int key);           // Delete a key from the BST
    void displayInorder() const;       // Display an inorder traversal of the BST
    int findFullBTLevel() const;       // Find the maximum level at which the tree is a full binary tree
    int lowestCommonAncestor(int A, int B) const; // Find the lowest common ancestor of keys A and B
    std::vector<int> maximumSumPath() const; // Find the path with the maximum sum
    int maximumWidth() const;          // Find the level with the maximum number of nodes
    std::vector<int> pathFromAtoB(int A, int B) const; // Find the path from key A to key B

private:
    struct Node {
        int key;
        Node* left;
        Node* right;
        Node(int k) : key(k), left(nullptr), right(nullptr) {}
    };

    Node* root;

    // Helper functions can be declared here
    void insertKey(Node*& node, int key);
    void deleteKey(Node*& node, int key);
    void displayInorder(Node* node) const;
    int findFullBTLevel(Node* node, int level) const;
    Node* lowestCommonAncestor(Node* node, int A, int B) const;
    int maximumSumPath(Node* node, std::vector<int>& path, std::vector<int>& maxPath, int sum, int& maxSum) const;
    int maximumWidth(Node* node) const;
    void pathFromAtoB(Node* node, int A, int B, std::vector<int>& path, std::vector<int>& resultPath) const;
};

## Usage

### Compilation
To compile the project, use the following commands:

```sh
g++ -c BST.cpp
g++ -o bst_program BST.o main.cpp
```

### Example Main Program
Here is an example of how to use the BST class in a `main.cpp` file:

```cpp
#include "BST.h"
#include <iostream>
#include <vector>

int main() {
    std::vector<int> keys = {10, 5, 1, 7, 40, 50};
    BST bst(keys);

    bst.insertKey(20);
    bst.displayInorder(); // Should display the BST in inorder

    bst.deleteKey(10);
    bst.displayInorder(); // Should display the BST after deletion

    std::cout << "Full Binary Tree Level: " << bst.findFullBTLevel() << std::endl;
    std::cout << "Lowest Common Ancestor of 1 and 7: " << bst.lowestCommonAncestor(1, 7) << std::endl;
    std::vector<int> maxSumPath = bst.maximumSumPath();
    std::cout << "Maximum Sum Path: ";
    for (int key : maxSumPath) {
        std::cout << key << " ";
    }
    std::cout << std::endl;
    std::cout << "Maximum Width Level: " << bst.maximumWidth() << std::endl;
    std::vector<int> pathFromAtoB = bst.pathFromAtoB(1, 7);
    std::cout << "Path from 1 to 7: ";
    for (int key : pathFromAtoB) {
        std::cout << key << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

### Execution
After compiling the program, run the executable:

```sh
./bst_program
```

## Contribution
If you wish to contribute to this project, please fork the repository, create a new branch, and submit a pull request with your changes.

## License
This project is licensed under the MIT License.

## Contact
For any inquiries or issues, please contact Ahmet Furkan KIZIL at furkan.kizil@ug.bilkent.edu.tr
