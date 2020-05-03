//
// Created by Jaquan Jones on 5/3/20.
//

#ifndef QUICKSORT_SORT_H
#define QUICKSORT_SORT_H

#include <ctime>
#include <iostream>

enum pivotType {
    MIDDLE, MEDIAN
};

class Sort {
public:
    Sort();

    void QuickSort(int[], int, int);
    void QuickSortMedian(int[], int, int);
    void QuickWithInsert(int[], int, int);
    void QuickSortMedianInsert(int[], int, int);

    // to confirm accurate sorting
    //void testPrint(int[], int, int, int);

private:
    int index;

    void quickSort(int[], int, int);
    void quickSortMedian(int[], int, int);
    void quickWithInsert(int[], int, int);
    void quickSortMedianInsert(int[], int, int);

    static void insertionSort(int[], int, int);
    static int getIndex(pivotType, int[], int, int);
    static int partition(int[], int, int, int);
    static void swap(int *, int *);
};


#endif //QUICKSORT_SORT_H
