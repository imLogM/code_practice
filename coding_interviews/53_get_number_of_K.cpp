#include <iostream>

int binSearch1(int array[], int lo, int hi, int elem) {
    if (array == nullptr || hi <= lo) {return 0;}
    while (hi > lo) {
        int mi = (lo + hi) / 2;
        if (array[mi] >= elem) { hi = mi; }
        else { lo = mi+1; }
    }
    return lo;
}

int binSearch2(int array[], int lo, int hi, int elem) {
    if (array == nullptr || hi <= lo) {return 0;}
    while (hi > lo) {
        int mi = (lo + hi) / 2;
        if (array[mi] > elem) { hi = mi; }
        else { lo = mi+1; }
    }
    return --lo;
}

int main(int argc, char** argv) {
    int array[] = {1,2,3,3,3,3,4,5};
    printf("%d\n", binSearch2(array, 0, 8, 3)-binSearch1(array, 0, 8, 3)+1);
    return 0;
}