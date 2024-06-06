/**
* Title: Binary Search Trees
* Author : Ahmet Furkan KIZIL
* ID: 22203112
* Section : 3
* Homework : 1
* Description : Binary Search Tree with required implementations
*/

#include "analysis.h"
#include <ctime>
#include "BST.h"

void analysis::timeAnalysis() {
    int keys[] = {};
    int size = 0;
    BST bst(keys, size);

    clock_t start = clock();
    for (int i = 0; i < 10000; ++i) {
        int randomKey = rand();
        bst.insertKey(randomKey);

        if ((i + 1) % 1000 == 0) {
            clock_t end = clock();
            double elapsedSeconds = static_cast<double>(end - start) / CLOCKS_PER_SEC;
            start = end;
            cout << "Inserted " << (i + 1) << " nodes. Time taken: " << elapsedSeconds << " seconds. Height: " << bst.getHeight() << endl;
        }
    }
}

