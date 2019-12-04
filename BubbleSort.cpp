//
// Created by Henry Evans on 12/3/19.
//
#include "Data.h"
#include "BubbleSort.h"
#include <vector>
using namespace std;

template <typename Type>
void BubbleSort::bubbleSort(vector<Type>& data){
    Type temp;
    for (int i = 0 ; i < data.size() - 1; i++){
        for (int j = 0 ; j < data.size() - i - 1; j++){
            if (data.at(j) < data.at(j + 1)){
                temp = data.at(j);
                data.at(j) = data.at(j + 1);
                data.at(j + 1) = temp;
            }
        }
    }
}
