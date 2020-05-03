//
// Created by Jaquan Jones on 5/3/20.
//

#include "Sort.h"

Sort::Sort() {
    index = 0;
}

void Sort::QuickSort(int *list, int low, int high) {
    clock_t start, end, duration;

    start = clock();
    quickSort(list, low, high);
    end = clock();
    duration = difftime(end, start);

    std::cout << "Quick sort time, with pivot middle element: " << duration << std::endl;
}

void Sort::QuickSortMedian(int *list, int low, int high) {
    clock_t start, end, duration;

    start = clock();
    quickSortMedian(list, low, high);
    end = clock();
    duration = difftime(end, start);

    std::cout << "Quick sort time, with pivot median element: " << duration << std::endl;
}

void Sort::QuickWithInsert(int *list, int low, int high) {
    clock_t start, end, duration;

    start = clock();
    quickWithInsert(list, low, high);
    end = clock();
    duration = difftime(end, start);

    std::cout << "Quick sort and insertion sort time, with pivot middle element: " << duration << std::endl;
}

void Sort::QuickSortMedianInsert(int *list, int low, int high) {
    clock_t start, end, duration;

    start = clock();
    quickSortMedianInsert(list, low, high);
    end = clock();
    duration = difftime(end, start);

    std::cout << "Quick sort and insertion sort time, with pivot median element: " << duration << std::endl;
}

void Sort::quickSort(int *list, int low, int high) {
    index = getIndex(MIDDLE, list, low, high);

    if (low < index - 1) {
        quickSort(list, low, index - 1);
    }
    if (index < high) {
        quickSort(list, index, high);
    }
}

void Sort::quickSortMedian(int *list, int low, int high) {
    index = getIndex(MEDIAN, list, low, high);

    if (low < index - 1) {
        quickSortMedian(list, low, index - 1);
    }
    if (index < high) {
        quickSortMedian(list, index, high);
    }
}

void Sort::quickWithInsert(int *list, int low, int high) {
    if ((high - low) < 20) {
        insertionSort(list, low, high);
    }

    index = getIndex(MIDDLE, list, low, high);

    if (low < index - 1) {
        quickSort(list, low, index - 1);
    }
    if (index < high) {
        quickSort(list, index, high);
    }
}

void Sort::quickSortMedianInsert(int *list, int low, int high) {
    if ((high - low) < 20) {
        insertionSort(list, low, high);
    }

    index = getIndex(MEDIAN, list, low, high);

    if (low < index - 1) {
        quickSortMedian(list, low, index - 1);
    }
    if (index < high) {
        quickSortMedian(list, index, high);
    }
}

void Sort::insertionSort(int *list, int low, int high) {
    int a, b;
    for (int i = low + 1; i < high + 1; i++) {
        a = list[i];
        b = i - 1;
        while (b >= 0 && list[b] > a) {
            list[b + 1] = list[b];
            b = b - 1;
        }
        list[b + 1] = a;
    }
}

int Sort::partition(int *list, int low, int high, int pivot) {
    while (low <= high) {
        while (list[low] < pivot) low++;
        while (list[high] > pivot) high--;

        if (low <= high) {
            swap(&list[low], &list[high]);
            low++;
            high--;
        }
    }
    return low;
}

void Sort::swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int Sort::getIndex(pivotType pType, int *list, int low, int high) {
    if (pType == MIDDLE) {
        int pivot = list[(low + high) / 2];
        return partition(list, low, high, pivot);
    } else if (pType == MEDIAN) {
        int mid = (low + high) / 2;
        int pivot = list[(low + mid + high) / 3];
        return partition(list, low, high, pivot);
    } else {
        return 0;
    }
}

// ***TEST***
//void Sort::testPrint(int *list, int low, int high, int listSize) {
//        std::cout << "Before:\n";
//        for(int i = 0; i < listSize; i++) {
//            std::cout << list[i] << " ";
//        }
//        quickWithInsert(list, low, high);
//    std::cout << "\nAfter:\n";
//    for(int i = 0; i < listSize; i++) {
//        std::cout << list[i] << " ";
//    }
//}
