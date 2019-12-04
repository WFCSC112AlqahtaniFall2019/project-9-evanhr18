//
// Created by Henry Evans on 12/3/19.
//

#ifndef PROJECT9_MERGESORT_H
#define PROJECT9_MERGESORT_H


#include <iostream>
#include <vector>
using namespace std;

class MergeSort{
public:
    template <typename Type>
    void mergeSort(vector<Type>& x, vector<Type>& temp, int left, int right);
    template <typename Type>
    void mergeSortedLists(vector<Type>& x, vector<Type>& temp, int leftPos, int rightPos, int rightEnd);
};


#endif //PROJECT9_MERGESORT_H
