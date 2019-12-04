//
// Created by Henry Evans on 12/3/19.
//

#include "SelectionSort.h"
#include <vector>
using namespace std;

template<typename Type>
void SelectionSort::selectionSort(vector<Type>& x) {
    int min;
    Type temp;

    for (int i = 0; i < x.size() - 1; ++i) {
        min = i;
        for (int j = i + 1; j < x.size(); ++j) {
            if (x.at(j) < x.at(min) ) {
                min = j;
            }
        }
        temp= x.at(i);
        x.at(i) = x.at(min);
        x.at(min) = temp;
    }
}