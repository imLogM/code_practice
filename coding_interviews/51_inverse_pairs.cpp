#include <iostream>


int merge(int array[], int lo, int mi, int hi) {
    if (array == nullptr) { return 0; }

    int* A = array + lo;
    int lenA = hi - lo;

    int lenB = mi - lo;
    int* B = new int[lenB];
    for (int i=0; i<lenB; ++i) {
        B[i] = A[i];
    }

    int lenC = hi - mi;
    int* C = array + mi;

    int i=0, j=0, k=0;
    int inversion_count = 0;
    for ( ; i<lenA || j<lenB || k<lenC; ) {
        if ((j<lenB) && ((k>=lenC) || B[j]<C[k])) {
            A[i] = B[j];
            ++i; ++j;
        }
        if ((k<lenC) && ((j>=lenB) || B[j]>C[k])) {
            A[i] = C[k];
            ++i; ++k;
            inversion_count += lenB - j;
        }
    }

    delete[] B;
    return inversion_count;
}

int mergeSort(int array[], int lo, int hi) {
    if (array == nullptr || lo <0 || hi-lo<2) { return 0; }

    int inversion_count = 0;

    int mi = (lo+hi) / 2;
    inversion_count += mergeSort(array, lo, mi);
    inversion_count += mergeSort(array, mi, hi);
    inversion_count += merge(array, lo, mi, hi);
    return inversion_count;
}

int main(int argc, char** argv) {
    int array[] = {7,5,6,4,3};
    printf("%d\n", mergeSort(array, 0, 5));
    return 0;
}