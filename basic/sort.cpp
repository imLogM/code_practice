#include <iostream>
#include <cstdio>
#include <ctime>

void bubbleSort(int array[], int lo, int hi) {
    if (array == nullptr) { return; }
    if (lo < 0 || hi <= lo) { return; }

    while (lo < hi) {
        for (int i=lo; i<hi-1; ++i) {
            if (array[i] > array[i+1]) {
                std::swap(array[i], array[i+1]);
            }
        }
        --hi;
    }
}

void merge(int array[], int lo, int mi, int hi) {
    if (array == nullptr) { return; }
    if (lo<0 || lo>=hi || lo>=mi || mi>=hi) { return; }

    int* A = array + lo;

    int* B = new int[mi-lo];
    int lenB = mi - lo;
    for (int i=0; i<lenB; ++i) {
        B[i] = array[i+lo];
    }

    int* C = array + mi;
    int lenC = hi - mi;

    int i = 0, j = 0, k = 0;
    for ( ; j<lenB || k<lenC; ) {
        if ( (j<lenB) && (k>=lenC || B[j]<=C[k]) ) {
            A[i] = B[j];
            ++i; ++j;
        } else if ( (k<lenC) && ((j>=lenB) || (B[j]>C[k])) ){
            A[i] = C[k];
            ++i; ++k;
        }
    }

    delete[] B;
}

void mergeSort(int array[], int lo, int hi) {
    if (array == nullptr) { return; }
    if (lo<0 || hi-lo<2) { return; }

    int mi = (lo+hi)/2;
    mergeSort(array, lo, mi);
    mergeSort(array, mi, hi);
    merge(array, lo, mi, hi);
}

int partition(int array[], int lo, int hi) {   // [lo, hi)
    if (array == nullptr) { return lo; }
    srand((unsigned int) time(nullptr));
    std::swap(array[lo], array[rand() % (hi-lo) + lo]);
    int pivot = array[lo];
    while (lo < hi-1) {
        while ( (lo<hi-1) && (array[hi-1]>=pivot) ) {
            --hi;
        }
        array[lo] = array[hi-1];
        while ( (lo<hi-1) && (array[lo]<=pivot) ) {
            ++lo;
        }
        array[hi-1] = array[lo];
    }
    array[lo] = pivot;
    return lo;
}

void quickSort(int array[], int lo, int hi) {  // [lo, hi)
    if (array == nullptr) { return; }
    if (hi - lo <= 1) { return; }

    int mi = partition(array, lo, hi);   //[lo, hi)
    quickSort(array, lo, mi);
    quickSort(array, mi+1, hi);
}

int main(int argc, char** argv) {
    int array[] = {4,2,1,6,3,7,5,9,8};
    int length = sizeof(array) / sizeof(array[0]);
//    bubbleSort(array, 1, length-1);
//    mergeSort(array, 1, length-1);
    quickSort(array, 1, length-1);
    for (int i=0; i<length; ++i) {
        printf("%d,", array[i]);
    }
    printf("\n");
    return 0;
}