//
// Created by Henry Evans on 12/3/19.
//

#include "MergeSort.h"
using namespace std;

template <typename Type>
void MergeSort::mergeSortedLists(vector<Type>& x, vector<Type>& temp, int leftPos, int rightPos, int rightEnd) {
    int leftEnd = rightPos - 1;
    int tempPos = leftPos;
    int numElements = rightEnd - leftPos + 1;

    while (leftPos <= leftEnd && rightPos <= rightEnd) {
        if (x[leftPos] <= x[rightPos]) {
            temp[tempPos++] = x[leftPos++];
        } else {
            temp[tempPos++] = x[rightPos++];
        }
    }
    while (leftPos <= leftEnd) {
        temp[tempPos++] = x[leftPos++];
    }
    while (rightPos <= rightEnd) {
        temp[tempPos++] = x[rightPos++];
    }
    for (int i = 0; i < numElements; i++, --rightEnd) {
        x[rightEnd] = temp[rightEnd];
    }
}

template <typename Type>
void MergeSort::mergeSort(vector<Type>& x, vector<Type>& temp, int left, int right) {
    if (left < right) {
        int center = ( left + right ) / 2;
        mergeSort(x, temp, left, center);
        mergeSort(x, temp, center + 1, right);
        mergeSortedLists(x, temp, left, center + 1, right);
    }
}