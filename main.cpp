#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
#include "Data.h"
#include "BubbleSort.h"
#include "SelectionSort.h"
#include "QuickSort.h"
#include "MergeSort.h"
using namespace std;

template <typename Type>
void bubbleSort(vector<Type> &dataVB);
template <typename Type>
void selectionSort(vector<Type> &dataVS);
template <typename Type>
void quickSort(vector<Type> &dataVQ, int i, int k);
template <typename Type>
int split(vector<Type> &dataVQ, int i, int k);
template <typename Type>
void mergeSortedLists(vector<Type>& dataVM, vector<Type>& tmp, int leftPos, int rightPos, int rightEnd);
template <typename Type>
void mergeSort(vector<Type>& dataVM, vector<Type>& tmp, int left, int right);

int main() {

    vector<int> intV;
    vector<int> intV_B;
    vector<int> intV_S;
    vector<int> intV_Q;
    vector<int> intV_M;
    string fullName;
    string shotTime;
    vector<Data> dataV;
    vector<Data> dataV_B;
    vector<Data> dataV_S;
    vector<Data> dataV_Q;
    vector<Data> dataV_M;

    srand(time(0));

    BubbleSort bs;
    SelectionSort ss;
    QuickSort qs;
    MergeSort ms;
    ifstream in;

    in.open("../NBA_Shots_2014.csv");

    if (!in.is_open()){
        cout << "Input file not opened correctly" << endl;
        return 1;
    }

    cout << "Reading ../NBA_Shots_2014.csv..." << endl;
    while(!in.eof()){

        getline(in, fullName, ',');
        getline(in, shotTime);

        Data shot(fullName, shotTime);
        dataV.push_back(shot);

    }

    for (int i = 0; i < 100; i++){

        dataV_Q.push_back(dataV.at(i));
        dataV_M.push_back(dataV.at(i));
        dataV_B.push_back(dataV.at(i));
        dataV_S.push_back(dataV.at(i));

    }

    for (int k = 0; k < 100; k++){
        intV.push_back((rand() % 100) + 1);
    }

    for (int i = 0; i < intV.size(); i++){
        intV_B.push_back(intV.at(i));
        intV_S.push_back(intV.at(i));
        intV_Q.push_back(intV.at(i));
        intV_M.push_back(intV.at(i));
    }

    clock_t bubbleSortDataStart = clock();
    bubbleSort(dataV_B);
    clock_t bubbleSortDataEnd = clock();

    clock_t selectionSortDataStart = clock();
    selectionSort(dataV_S);
    clock_t selectionSortDataEnd = clock();

    clock_t quickSortDataStart = clock();
    quickSort(dataV_Q, 0, dataV_Q.size() - 1);
    clock_t quickSortDataEnd = clock();

    clock_t mergeSortDataStart = clock();
    vector<Data> DataTemp(dataV_M.size());
    mergeSort(dataV_M, DataTemp, 0, dataV_M.size()-1);
    clock_t mergeSortDataEnd = clock();

    clock_t bubbleSortIntStart = clock();
    bubbleSort(intV_B);
    clock_t bubbleSortIntEnd = clock();

    clock_t selectionSortIntStart = clock();
    selectionSort(intV_S);
    clock_t selectionSortIntEnd = clock();

    clock_t quickSortIntStart = clock();
    quickSort(intV_Q, 0, intV_Q.size() - 1);
    clock_t quickSortIntEnd = clock();

    clock_t mergeSortIntStart = clock();
    vector<int> IntTemp(intV_M.size());
    mergeSort(intV_M, IntTemp, 0, intV_M.size()-1);
    clock_t mergeSortIntEnd = clock();


    double bubbleSortData = double(bubbleSortDataEnd - bubbleSortDataStart) / CLOCKS_PER_SEC;
    double selectionSortData = double(selectionSortDataEnd - selectionSortDataStart) / CLOCKS_PER_SEC;
    double quickSortData = double(quickSortDataEnd - quickSortDataStart) / CLOCKS_PER_SEC;
    double mergeSortData = double(mergeSortDataEnd - mergeSortDataStart) / CLOCKS_PER_SEC;
    double bubbleSortInt = double(bubbleSortIntEnd - bubbleSortIntStart) / CLOCKS_PER_SEC;
    double selectionSortInt = double(selectionSortIntEnd - selectionSortIntStart) / CLOCKS_PER_SEC;
    double quickSortInt = double(quickSortIntEnd - quickSortIntStart) / CLOCKS_PER_SEC;
    double mergeSortInt = double(mergeSortIntEnd - mergeSortIntStart) / CLOCKS_PER_SEC;

    cout << "Bubble Sort Random Ints: " << bubbleSortInt << endl;
    cout << "Selection Sort Random Ints: " << selectionSortInt << endl;
    cout << "Quick Sort Random Ints: " << quickSortInt << endl;
    cout << "Merge Sort Random Ints: " << mergeSortInt << endl;
    cout << "Bubble Sort Shots: " << bubbleSortData << endl;
    cout << "Selection Sort Shots: " << selectionSortData << endl;
    cout << "Quick Sort Shots: " << quickSortData << endl;
    cout << "Merge Sort Shots: " << mergeSortData << endl;

    in.close();

    return 0;
}

template <typename Type>
void bubbleSort(vector<Type> &dataVB){
    Type tempData;
    for (int i = 0 ; i < dataVB.size() - 1; i++){
        for (int j = 0 ; j < dataVB.size() - i - 1; j++){
            if (dataVB.at(j) > dataVB.at(j + 1)){
                tempData = dataVB.at(j);
                dataVB.at(j) = dataVB.at(j + 1);
                dataVB.at(j + 1) = tempData;
            }
        }
    }
}

template<typename Type>
void selectionSort(vector<Type> &dataVS) {
    int smallestData;
    Type tempSelectionData;

    for (int i = 0; i < dataVS.size() - 1; ++i) {

        smallestData = i;
        for (int j = i + 1; j < dataVS.size(); ++j) {
            if (dataVS.at(j) < dataVS.at(smallestData) ) {
                smallestData = j;
            }
        }

        tempSelectionData = dataVS.at(i);
        dataVS.at(i) = dataVS.at(smallestData);
        dataVS.at(smallestData) = tempSelectionData;
    }
}

template<typename Type>
void quickSort(vector<Type> &dataVQ, int i, int k) {
    int j;

    if (i >= k) {
        return;
    }

    j = split(dataVQ, i, k);

    quickSort(dataVQ, i, j);
    quickSort(dataVQ, j + 1, k);
}

template<typename Type>
int split(vector<Type> &dataVQP, int i, int k) {
    int l;
    int h;
    int midpoint;
    Type pivot;
    Type temp;
    bool done;

    midpoint = i + (k - i) / 2;
    pivot = dataVQP.at(midpoint);

    done = false;
    l = i;
    h = k;

    while (!done) {

        while (dataVQP.at(l) < pivot) {
            ++l;
        }

        while (pivot < dataVQP.at(h)) {
            --h;
        }

        if (l >= h) {
            done = true;
        }
        else {
            temp = dataVQP.at(l);
            dataVQP.at(l) = dataVQP.at(h);
            dataVQP.at(h) = temp;

            ++l;
            --h;
        }
    }
    return h;
}

template <typename Type>
void mergeSortedLists(vector<Type>& dataVM, vector<Type>& tmp, int leftPos, int rightPos, int rightEnd) {
    int leftEnd = rightPos - 1;
    int tempPos = leftPos;
    int numElements = rightEnd - leftPos + 1;

    while (leftPos <= leftEnd && rightPos <= rightEnd) {
        if (dataVM[leftPos] < dataVM[rightPos]) {
            tmp[tempPos++] = dataVM[leftPos++];
        } else {
            tmp[tempPos++] = dataVM[rightPos++];
        }
    }
    while (leftPos <= leftEnd) {
        tmp[tempPos++] = dataVM[leftPos++];
    }
    while (rightPos <= rightEnd) {
        tmp[tempPos++] = dataVM[rightPos++];
    }
    for (int i = 0; i < numElements; i++, --rightEnd) {
        dataVM[rightEnd] = tmp[rightEnd];
    }
}

template <typename Type>
void mergeSort(vector<Type>& dataVM, vector<Type>& tmp, int left, int right) {
    if (left < right) {
        int center = ( left + right ) / 2;
        mergeSort(dataVM, tmp, left, center);
        mergeSort(dataVM, tmp, center + 1, right);
        mergeSortedLists(dataVM, tmp, left, center + 1, right);
    }
}