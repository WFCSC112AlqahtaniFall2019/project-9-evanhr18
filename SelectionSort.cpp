//
// Created by Henry Evans on 12/3/19.
//

#include "SelectionSort.h"
#include <vector>
using namespace std;

template<typename Type>
void SelectionSort::selectionSort(vector<Type>& x) {
    int min;
    Type temp;      // Temporary variable for swap

    for (int i = 0; i < x.size() - 1; ++i) {

        // Find index of smallest remaining element
        min = i;
        for (int j = i + 1; j < x.size(); ++j) {
            if (x.at(j) < x.at(min) ) {
                min = j;
            }
        }

        // Swap numbers[i] and numbers[indexSmallest]
        temp= x.at(i);
        x.at(i) = x.at(min);
        x.at(min) = temp;
    }
}