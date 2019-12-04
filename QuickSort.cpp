//
// Created by Henry Evans on 12/3/19.
//

#include "QuickSort.h"
#include <vector>
using namespace std;

template<typename Type>
void QuickSort::quickSort(vector<Type>& x, int i, int k) {
    int j;

    /* Base case: If there are 1 or zero elements to sort,
     partition is already sorted */
    if (i >= k) {
        return;
    }

    /* Partition the data within the array. Value j returned
     from partitioning is location of last element in low partition. */
    j = split(x, i, k);

    /* Recursively sort low partition (i to j) and
     high partition (j + 1 to k) */
    Quicksort(x, i, j);
    Quicksort(x, j + 1, k);
}

template<typename Type>
int QuickSort::split(vector<Type>& x, int i, int k) {
    int l;
    int h;
    int mid;
    Type pivot;
    Type temp;
    bool done;

    /* Pick middle element as pivot */
    mid = i + (k - i) / 2;
    pivot = x[mid];

    done = false;
    l = i;
    h = k;

    while (!done) {

        /* Increment l while numbers[l] < pivot */
        while (x[l] < pivot) {
            ++l;
        }

        /* Decrement h while pivot < numbers[h] */
        while (pivot < x[h]) {
            --h;
        }

        /* If there are zero or one elements remaining,
         all numbers are partitioned. Return h */
        if (l >= h) {
            done = true;
        }
        else {
            /* Swap numbers[l] and numbers[h],
             update l and h */
            temp = x[l];
            x[l] = x[h];
            x[h] = temp;

            ++l;
            --h;
        }
    }

    return h;
}
