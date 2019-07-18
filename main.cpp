#include <cstdio>
#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

int partition(vector<int>& array, int lo, int hi) {
    if (array.empty()) { return -1; }
    if (lo<0 || lo>=hi) { return -1; }

//    srand((unsigned int) time(nullptr));
//    swap(array[lo], array[rand()%array.size()]);

    int pivot = array[lo];
    while (lo < hi) {
        while ( (lo < hi) && array[hi-1] >= pivot) {
            --hi;
        }
        swap(array[lo], array[hi-1]);
        while ( (lo < hi) && array[lo] <= pivot) {
            ++lo;
        }
        swap(array[lo], array[hi-1]);
    }
    array[lo] = pivot;
    return lo;
}

void quickSort(vector<int>& array, int lo, int hi) {
    if (array.empty()) { return; }
    if (lo<0 || lo>=hi) { return; }

    int mid = partition(array, lo, hi);
    quickSort(array, lo, mid);
    quickSort(array, mid+1, hi);
}

int main() {
    vector<int> array = {2,23,6,87,12,11,39};

    quickSort(array, 0, array.size());
    for (int v:array) {
        printf("%d, ", v);
    }
    return 0;
}