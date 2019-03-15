#include <iostream>

int binSearch(const int array[], int lo, int hi, int elem) {
    if (array == nullptr) { return 0; }
    if (lo<0 || hi<=lo) { return 0; }

    while (lo < hi) {
        int mi = (lo + hi) / 2;
        if (array[mi] > elem) {
            hi = mi;
        } else {
            lo = mi+1;
        }
    }
    return --lo;
}

int main(int argc, char** argv) {
    int array[] = {4,6,8,10,15};
    printf("%d\n", binSearch(array, 0, 5, 9));
    return 0;
}
