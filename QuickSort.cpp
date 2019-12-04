//
// Created by Henry Evans on 12/3/19.
//

#include "QuickSort.h"
#include <vector>
using namespace std;

template<typename Type>
void QuickSort::quickSort(vector<Type>& x, int i, int k) {
    int j;

    if (i >= k) {
        return;
    }
    j = split(x, i, k);
    Quicksort(x, i, j);
    Quicksort(x, j + 1, k);
}

template<typename Type>
int QuickSort::split(vector<Type>& x, int i, int k) {
    int l = i;
    int h = k;
    int mid = i + (k - i) / 2;
    Type pivot = x[mid];
    Type temp;
    bool finished = false;

    while (!finished) {

        while (x[l] < pivot) {
            ++l;
        }
        while (pivot < x[h]) {
            --h;
        }
        if (l >= h) {
            finished = true;
        }
        else {
            temp = x[l];
            x[l] = x[h];
            x[h] = temp;
            ++l;
            --h;
        }
    }

    return h;
}
