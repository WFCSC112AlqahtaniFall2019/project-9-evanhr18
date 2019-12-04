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
int Partition(vector<Type> &dataVQ, int i, int k);
template <typename Type>
void mergeSortedLists(vector<Type>& dataVM, vector<Type>& tmp, int leftPos, int rightPos, int rightEnd);
template <typename Type>
void mergeSort(vector<Type>& dataVM, vector<Type>& tmp, int left, int right);

int main() {

    vector<Data> dataV;
    vector<Data> dataV_B;
    vector<Data> dataV_S;
    vector<Data> dataV_Q;
    vector<Data> dataV_M;
    vector<int> intV;
    vector<int> intV_B;
    vector<int> intV_S;
    vector<int> intV_Q;
    vector<int> intV_M;
    string firstName;
    string lastName;
    double shotTime;

    // Seed random number generator
    srand(time(0));

    BubbleSort bs;
    SelectionSort ss;
    QuickSort qs;
    MergeSort ms;

    //Initializes input and output streams
    ifstream in;

    //Opens files
    in.open("NBA_Shots_2014.csv");

    //Checks to see if files have been opened properly
    if (!in.is_open()){
        cout << "Input file not opened correctly" << endl;
        return 1;
    }



    cout << "Reading ../NBA_Shots_2014.csv..." << endl;
    while(!in.eof()){
        getline(in, firstName, ' ');
        getline(in, lastName, ' ');
        getline(in, shotTime, ' ');
        string playerName = firstName + " " + lastName;

        //Creates new data object
        Data shot (playerName, stoi(shotTime));

        //Pushes new data object to stack, queue, and priority queue
        dataV.push_back(shot);
    }

    for (int j = 0; j < 100; j++){
        dataV_B.push_back(dataV.at(j));
        dataV_S.push_back(dataV.at(j));
        dataV_Q.push_back(dataV.at(j));
        dataV_M.push_back(dataV.at(j));
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


    cout << "Bubble sort objects" << endl;
    clock_t start_bubbleSort_data = clock();
    bubbleSort(dataV_B);
    clock_t end_bubbleSort_data = clock();

    cout << "Selection sort objects" << endl;
    clock_t start_selectionSort_data = clock();
    selectionSort(dataV_S);
    clock_t end_selectionSort_data = clock();

    cout << "Quick sort objects" << endl;
    clock_t start_quickSort_data = clock();
    quickSort(dataV_Q, 0, dataV_Q.size() - 1);
    clock_t end_quickSort_data = clock();

    cout << "Merge sort objects" << endl;
    clock_t start_mergeSort_data = clock();
    vector<Data> tempData(dataV_M.size());
    mergeSort(dataV_M, tempData, 0, dataV_M.size()-1);
    clock_t end_mergeSort_data = clock();

    cout << "Bubble sorting integers" << endl;
    clock_t start_bubbleSort_int = clock();
    bubbleSort(intV_B);
    clock_t end_bubbleSort_int = clock();

    cout << "Selection sorting integers" << endl;
    clock_t start_selectionSort_int = clock();
    selectionSort(intV_S);
    clock_t end_selectionSort_int = clock();

    cout << "Quick sorting integers" << endl;
    clock_t start_quickSort_int = clock();
    quickSort(intV_Q, 0, intV_Q.size() - 1);
    clock_t end_quickSort_int = clock();

    cout << "Merge sorting integers" << endl;
    clock_t start_mergeSort_int = clock();
    vector<int> tempInts(intV_M.size());
    mergeSort(intV_M, tempInts, 0, intV_M.size()-1);
    clock_t end_mergeSort_int = clock();


    double elapsed_bubbleSort_data = double(end_bubbleSort_data - start_bubbleSort_data) / CLOCKS_PER_SEC;
    double elapsed_selectionSort_data = double(end_selectionSort_data - start_selectionSort_data) / CLOCKS_PER_SEC;
    double elapsed_quickSort_data = double(end_quickSort_data - start_quickSort_data) / CLOCKS_PER_SEC;
    double elapsed_mergeSort_data = double(end_mergeSort_data - start_mergeSort_data) / CLOCKS_PER_SEC;
    double elapsed_bubbleSort_int = double(end_bubbleSort_int - start_bubbleSort_int) / CLOCKS_PER_SEC;
    double elapsed_selectionSort_int = double(end_selectionSort_int - start_selectionSort_int) / CLOCKS_PER_SEC;
    double elapsed_quickSort_int = double(end_quickSort_int - start_quickSort_int) / CLOCKS_PER_SEC;
    double elapsed_mergeSort_int = double(end_mergeSort_int - start_mergeSort_int) / CLOCKS_PER_SEC;

    cout << "Bubble Sort Data: " << elapsed_bubbleSort_data << endl;
    cout << "Selection Sort Data: " << elapsed_selectionSort_data << endl;
    cout << "Quick Sort Data: " << elapsed_quickSort_data << endl;
    cout << "Merge Sort Data: " << elapsed_mergeSort_data << endl;
    cout << "Bubble Sort Ints: " << elapsed_bubbleSort_int << endl;
    cout << "Selection Sort Ints: " << elapsed_selectionSort_int << endl;
    cout << "Quick Sort Ints: " << elapsed_quickSort_int << endl;
    cout << "Merge Sort Ints: " << elapsed_mergeSort_int << endl;

    for (int i = 0; i < 50; i++){
        cout << dataV_B.at(i);
        cout << dataV_S.at(i);
        cout << dataV_Q.at(i);
        cout << dataV_M.at(i);
    }
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
    Type tempSelectionData;      // Temporary variable for swap

    for (int i = 0; i < dataVS.size() - 1; ++i) {

        // Find index of smallest remaining element
        smallestData = i;
        for (int j = i + 1; j < dataVS.size(); ++j) {
            if (dataVS.at(j) < dataVS.at(smallestData) ) {
                smallestData = j;
            }
        }

        // Swap numbers[i] and numbers[indexSmallest]
        tempSelectionData = dataVS.at(i);
        dataVS.at(i) = dataVS.at(smallestData);
        dataVS.at(smallestData) = tempSelectionData;
    }
}

template<typename Type>
void quickSort(vector<Type> &dataVQ, int i, int k) {
    int j;

    /* Base case: If there are 1 or zero elements to sort,
     partition is already sorted */
    if (i >= k) {
        return;
    }

    /* Partition the data within the array. Value j returned
     from partitioning is location of last element in low partition. */
    j = Partition(dataVQ, i, k);

    /* Recursively sort low partition (i to j) and
     high partition (j + 1 to k) */
    quickSort(dataVQ, i, j);
    quickSort(dataVQ, j + 1, k);
}

template<typename Type>
int Partition(vector<Type> &dataVQP, int i, int k) {
    int l;
    int h;
    int midpoint;
    Type pivot;
    Type temp;
    bool done;

    /* Pick middle element as pivot */
    midpoint = i + (k - i) / 2;
    pivot = dataVQP.at(midpoint); //Out of range occurs here

    done = false;
    l = i;
    h = k;

    while (!done) {

        /* Increment l while numbers[l] < pivot */
        while (dataVQP.at(l) < pivot) {
            ++l;
        }

        /* Decrement h while pivot < numbers[h] */
        while (pivot < dataVQP.at(h)) {
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