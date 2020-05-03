#include <iostream>
#include <random>
#include "Sort.h"
#include <cstdlib>

using namespace std;

int main() {
    Sort sort;
    random_device rand;

    int val;
    int SIZE = 100000;
    int listA[SIZE];

    for (int i = 0; i < SIZE; i++) {
        val = rand();
        listA[i] = abs(val);
    }

    cout << "Array size = " << SIZE << endl;
    sort.QuickSort(listA, 0, SIZE - 1);
    sort.QuickSortMedian(listA, 0, SIZE - 1);
    sort.QuickWithInsert(listA, 0, SIZE - 1);
    sort.QuickSortMedianInsert(listA, 0, SIZE - 1);
    cout << endl;

    SIZE = 300000;
    int listB[SIZE];

    for (int i = 0; i < SIZE; i++) {
        val = rand();
        listB[i] = abs(val);
    }

    cout << "Array size = " << SIZE << endl;
    sort.QuickSort(listB, 0, SIZE - 1);
    sort.QuickSortMedian(listB, 0, SIZE - 1);
    sort.QuickWithInsert(listB, 0, SIZE - 1);
    sort.QuickSortMedianInsert(listB, 0, SIZE - 1);
    cout << endl;

    return 0;
}

// ***Test***
/*
    SIZE = 20;
    int testList[SIZE];

    for (int i = 0; i < SIZE; i++) {
        val = rand();
        testList[i] = abs(val);
    }

    sort.testPrint(testList, 0, SIZE-1, SIZE);
    */