/**
* Title: Binary Search Trees
* Author : Ahmet Furkan KIZIL
* ID: 22203112
* Section : 3
* Homework : 1
* Description : Binary Search Tree with required implementations
*/

#include "BST.h"

BST::BST(int *keys, int size) {
    root = nullptr;
    for (int i = 0; i < size; ++i) {
        insertKeyMainForConstructor(keys[i], root);
    }
    cout << "BST with size " << size << " is created." << endl;
}

BST::~BST() {
    destroyTree(root);
}

void BST::insertKey(int key) {
    insertKeyMain(key, root);               // Change this afterwards
}

void BST::deleteKey(int key) {
    deleteKeyMain(key, root);
}

void BST::insertKeyMain(int key, Node *&root) {
    if(root == nullptr) {
        root = new Node(key, nullptr, nullptr);
        cout << "Key " << key << " is added." << endl;
    } else if (root->key > key) {
        if(root->leftChild == nullptr) {
            Node *newKey = new Node(key, nullptr, nullptr);
            root->leftChild = newKey;
            cout << "Key " << key << " is added." << endl;
        } else {
            insertKeyMain(key, root->leftChild);
        }
    } else if(root->key < key) {
        if(root->rightChild == nullptr) {
            Node *newKey = new Node(key, nullptr, nullptr);
            root->rightChild = newKey;
            cout << "Key " << key << " is added." << endl;
        } else {
            insertKeyMain(key, root->rightChild);
        }
    } else {
        cout << "Key " << key << " is not added. It exists!" << endl;
    }
}

void BST::insertKeyMainForConstructor(int key, Node *&root) {
    if(root == nullptr) {
        root = new Node(key, nullptr, nullptr);
    } else if (root->key > key) {
        if(root->leftChild == nullptr) {
            Node *newKey = new Node(key, nullptr, nullptr);
            root->leftChild = newKey;
        } else {
            insertKeyMainForConstructor(key, root->leftChild);
        }
    } else if(root->key < key) {
        if(root->rightChild == nullptr) {
            Node *newKey = new Node(key, nullptr, nullptr);
            root->rightChild = newKey;
        } else {
            insertKeyMainForConstructor(key, root->rightChild);
        }
    } else {
        return;
    }
}

void BST::deleteKeyMain(int key, Node *&root) {
    if(root == nullptr) {
        cout << "Key " << key << " is not deleted. It does not exist!" << endl;
        return;
    } else if (key == root->key) {
        deleteNode(root);
    } else if (key < root->key) {
        deleteKeyMain(key,root->leftChild);
    } else if (key > root->key) {
        deleteKeyMain(key,root->rightChild);
    }
}

// I've got help from the codes in slides "L3_Trees"
void BST::deleteNode(Node *&nodeToBeDeleted) {
    // The nodeToBeDeleted is a leaf (Case 1)
    if(nodeToBeDeleted->leftChild == nullptr && nodeToBeDeleted-> rightChild == nullptr) {
        int forPrinting = nodeToBeDeleted->key;
        delete nodeToBeDeleted;
        nodeToBeDeleted = nullptr;
        cout << "Key " << forPrinting << " is deleted." << endl;
    // The nodeToBeDeleted is having only a left child (Case 2a)
    } else if (nodeToBeDeleted->rightChild == nullptr) {
        int forPrinting = nodeToBeDeleted->key;
        Node *temp;
        temp = nodeToBeDeleted;
        nodeToBeDeleted = nodeToBeDeleted->leftChild;
        temp->leftChild = nullptr;
        delete temp;
        cout << "Key " << forPrinting << " is deleted." << endl;
    // The nodeToBeDeleted is having only a right child (Case 2b)
    } else if (nodeToBeDeleted->leftChild == nullptr){
        int forPrinting = nodeToBeDeleted->key;
        Node *temp;
        temp = nodeToBeDeleted;
        nodeToBeDeleted = nodeToBeDeleted->rightChild;
        temp->rightChild = nullptr;
        delete temp;
        cout << "Key " << forPrinting << " is deleted." << endl;
    // The nodeToBeDeleted is having both children (Case 3a). Process required
    } else {
        int forPrinting = nodeToBeDeleted->key;
        int keyTemp;
        process(nodeToBeDeleted, keyTemp);
        nodeToBeDeleted -> key = keyTemp;
        cout << "Key " << forPrinting << " is deleted." << endl;
    }
}

void BST::destroyTree(Node* node) {
    if (node == nullptr) {
        return;
    }
    destroyTree(node->leftChild);
    destroyTree(node->rightChild);
    delete node;
}

void BST::process(Node *&nodeToBeDeleted, int &temp) {
    if(nodeToBeDeleted->leftChild != nullptr) {
        process(nodeToBeDeleted->leftChild, temp);
    } else {
        Node * tempNode = nodeToBeDeleted;
        temp = nodeToBeDeleted->key;
        nodeToBeDeleted = nodeToBeDeleted->rightChild;
        tempNode->rightChild = nullptr;
        delete tempNode;
    }
}

void BST::displayInorder() {
    cout << "Inorder display is: ";
    displayInorderRecursively(root);
    cout << endl;
}

void BST::displayInorderRecursively(Node* currentNode) {

    if(currentNode == nullptr) {
        return;
    }
    if(currentNode->leftChild != nullptr) {
        displayInorderRecursively(currentNode->leftChild);
    }
    int maxValue = findMaxValue(root);
    if(currentNode -> key == maxValue) {
        cout << currentNode->key;
    } else{
        cout << currentNode->key << ", ";
    }
    if (currentNode->rightChild != nullptr) {
        displayInorderRecursively(currentNode->rightChild);
    }
}

void BST::findFullBTLevel() {
    int rightCounter = 1;
    int leftCounter = 1;
    Node* currentPtr = root;
    if(currentPtr == nullptr) {
        cout << "Full binary tree level is: 0"  << endl;
        return;
    }
    while (currentPtr->leftChild != nullptr && currentPtr -> rightChild != nullptr) {
        leftCounter ++;
        currentPtr = currentPtr->leftChild;
    }
    currentPtr = root;
    while (currentPtr->leftChild != nullptr && currentPtr -> rightChild != nullptr) {
        rightCounter ++;
        currentPtr = currentPtr->rightChild;
    }
    if(leftCounter <= rightCounter) {
        cout << "Full binary tree level is: " << leftCounter << endl;
    } else {
        cout << "Full binary tree level is: " << rightCounter << endl;
    }
}

void BST::lowestCommonAncestor(int A, int B) {
    Node *currentPtr = root;
    while (currentPtr != nullptr) {
        if (A < currentPtr->key && B < currentPtr->key) {
            currentPtr = currentPtr->leftChild;
        } else if (A > currentPtr->key && B > currentPtr->key) {
            currentPtr = currentPtr->rightChild;
        }
        else{
            cout << "Lowest common ancestor of " << A << " and " << B << " is: " << currentPtr->key << endl;
            return;
        }
    }
}

void BST::maximumSumPath(Node* node, int sum, int* path, int pathLength, int& maxSum, int*& maxPath, int& maxPathLength) {
    if (node == nullptr) {
        return;
    }

    sum = sum + node-> key;
    path[pathLength++] = node-> key;

    if ((node->rightChild == nullptr) && (node->leftChild == nullptr)) {
        if (sum > maxSum) {
            maxSum = sum;

            if (maxPathLength < pathLength) {
                delete[] maxPath;
                maxPath = new int[pathLength];
            }

            maxPathLength = pathLength;

            for (int i = 0; i < pathLength; i++) {
                maxPath[i] = path[i];
            }
        }
    }
    maximumSumPath(node->leftChild, sum, path, pathLength, maxSum, maxPath, maxPathLength);
    maximumSumPath(node->rightChild, sum, path, pathLength, maxSum, maxPath, maxPathLength);
}

void BST::maximumSumPath() {
    int maxSum = -1;
    int pathLength = 0;
    int maxPathLen = 0;

    int* maxPath = new int[750];
    int* path = new int[750];

    maximumSumPath(root, 0, path, pathLength, maxSum, maxPath, maxPathLen);

    cout << "Maximum sum path is: ";
    for (int i = 0; i < maxPathLen; i++) {
        cout << maxPath[i];
        if (i != maxPathLen-1) {
            cout << ", ";
        }
    }
    cout << endl;

    delete[] path;
    delete[] maxPath;
}

void BST::maximumWidth() {
    cout << "Maximum level is: ";
    Node* levelCollection[750];
    int front = 0;
    int back = 0;
    if (root == nullptr) {
        cout << endl;
        return;
    }
    levelCollection[back] = root;
    back++;

    int maxNodes = 0;
    int level = 0;
    int maxLevel = 0;
    while (front != back) {
        int nodeCount = back - front;

        if (nodeCount > maxNodes) {
            maxNodes = nodeCount;
            maxLevel = level;
        }

        while (nodeCount--) {
            Node* node = levelCollection[front++];
            if (node->leftChild != nullptr)
                levelCollection[back++] = node->leftChild;
            if (node->rightChild != nullptr)
                levelCollection[back++] = node->rightChild;
        }

        level++;
    }

    back = 0;
    front = 0,
            level = 0;
    levelCollection[back] = root;
    back++;
    while (front != back) {
        int nodeCount = back - front;
        if (level == maxLevel) {
            while (nodeCount--) {
                Node* node = levelCollection[front++];
                cout << node->key;
                if(nodeCount > 0) {
                    cout << ", ";
                }
                if (node->leftChild != nullptr){
                    levelCollection[back] = node->leftChild;
                    back++;
                }
                if (node->rightChild != nullptr) {
                    levelCollection[back] = node->rightChild;
                    back++;
                }
            }
            break;
        }
        while (nodeCount--) {
            Node* node = levelCollection[front++];
            if (node->leftChild != nullptr) {
                levelCollection[back] = node->leftChild;
                back++;
            }
            if (node->rightChild != nullptr) {
                levelCollection[back] = node->rightChild;
                back++;
            }
        }
        level++;
    }
    cout << endl;
}

void BST::pathFromAtoB(int A, int B) {
    Node *currentNode = root;

    if(exists(A) && exists(B)) {
        if(root->key < B && root->key > A) {
            cout << "Path from " << A << " to " << B << " is: ";
            searchSmallerPath(currentNode, A);
            searchHigherPath(currentNode, B, getSizeOfArray(currentNode, B));
            cout << endl;
        }
        else if(root->key < A && root->key > B) {
            cout << "Path from " << A << " to " << B << " is: ";
            searchSmallerPath(currentNode, A);
            searchHigherPath(currentNode, B, getSizeOfArray(currentNode, B));
            cout << endl;
        } else {

            if(A>=B) {
                cout << "Path from " << A << " to " << B << " is: ";
                searchMoreSmallerPath(currentNode, A, B);
                cout << endl;
            } else {
                cout << "Path from " << A << " to " << B << " is: ";
                searchMoreHigherPath(currentNode, A, B);
                cout << endl;
            }
        }
    } else {
        cout << "Doesn't exist!" << endl;
    }

}

void BST::searchSmallerPath(Node *currentNode, int A){
    if (currentNode == nullptr) {
        return;
    }
    if (currentNode->key == A) {
        cout << currentNode->key << ", ";
        return;
    }
    if (A < currentNode->key) {
        searchSmallerPath(currentNode->leftChild, A);
        cout << currentNode->key << ", ";
    } else {
        searchSmallerPath(currentNode->rightChild, A);
        cout << currentNode->key << ", ";
    }
}

void BST::searchMoreSmallerPath(Node *currentNode, int A, int B) {
    Node* targetNode;
    while (currentNode != NULL) {
        if (B > currentNode->key) {
            currentNode = currentNode->rightChild;
        }
        else if (B < currentNode->key) {
            currentNode = currentNode->leftChild;
        }
        else {
            targetNode = currentNode;
            break;
        }
    }
    searchSmallerPath(targetNode,A);
}


int BST::getSizeOfArray(Node *currentNode, int A){
    int numberOfNodes = 0;
    while (currentNode != NULL && currentNode->key != A)
    {
        numberOfNodes++;
        if (currentNode->key > A)
            currentNode = currentNode->leftChild;
        else
            currentNode = currentNode->rightChild;
    }
    return numberOfNodes+1;
}

void BST::searchHigherPath(Node *currentNode, int A, int size){
    int index = 0;
    int arr[size];
    while (currentNode != NULL && currentNode->key != A)
    {
        arr[index++] = currentNode->key;
        if (currentNode->key > A)
            currentNode = currentNode->leftChild;
        else
            currentNode = currentNode->rightChild;
    }
    arr[index++] = currentNode->key;

    for (int i = 1; i < size; i++) {
        if(i == (size-1)) {
            cout << arr[i] << "";
        } else {
            cout << arr[i] << ", ";
        }
    }
}

void BST::searchHigherPathSpecial(Node *currentNode, int A, int size){
    int index = 0;
    int arr[size];
    while (currentNode != NULL && currentNode->key != A)
    {
        arr[index++] = currentNode->key;
        if (currentNode->key > A)
            currentNode = currentNode->leftChild;
        else
            currentNode = currentNode->rightChild;
    }
    arr[index++] = currentNode->key;

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}

void BST::searchMoreHigherPath(Node *currentNode, int A, int B){
    Node* targetNode;
    while (currentNode != NULL) {
        if (A > currentNode->key) {
            currentNode = currentNode->rightChild;
        }
        else if (A < currentNode->key) {
            currentNode = currentNode->leftChild;
        }
        else {
            targetNode = currentNode;
            break;
        }
    }
    searchHigherPathSpecial(targetNode, B, (getSizeOfArray(targetNode, B)));
}

bool BST::exists(int A) {
    Node *currentNode = root;
    while (currentNode != nullptr) {
        if (A > currentNode->key) {
            currentNode = currentNode->rightChild;
        }
        else if (A < currentNode->key) {
            currentNode = currentNode->leftChild;
        }
        else {
            return true;
        }
    }
    return false;
}

int BST::findMaxValue(Node* currentNode) {
    if (currentNode == nullptr) {
        return -1;
    }

    while (currentNode->rightChild != nullptr) {
        currentNode = currentNode->rightChild;
    }

    return currentNode->key;
}

int BST::getHeight() {
    return getHeightRecursively(root);
}

int BST::getHeightRecursively(Node *currentNode) {
    // Base
    if (currentNode == nullptr) {
        return 0;
    }
    int leftHeight = getHeightRecursively(currentNode->leftChild);
    int rightHeight = getHeightRecursively(currentNode->rightChild);
    return max(leftHeight, rightHeight) + 1;
}





