//
// Created by Henry Evans on 12/3/19.
//

#ifndef PROJECT9_QUICKSORT_H
#define PROJECT9_QUICKSORT_H
#include <iostream>
#include <vector>

using namespace std;
class QuickSort{
public:
    template <typename Type>
    void quickSort(vector<Type>& x, int i, int k);
    template <typename Type>
    int split(vector<Type>& x, int i, int k);
};




#endif //PROJECT9_QUICKSORT_H
