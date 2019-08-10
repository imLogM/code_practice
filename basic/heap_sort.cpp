#include <cstdio>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

void HeapAdjust(vector<int>& heap, int n, int index) {
    if (heap.empty() || index>=n || index<0 || (int)heap.size()<n) { return; }

    int lchild = 2*index+1;
    int rchild = 2*index+2;

    int max = heap[index];
    int maxIndex = index;
    if (lchild<n && heap[lchild]>max) {
        max = heap[lchild];
        maxIndex = lchild;
    }
    if (rchild<n && heap[rchild]>max) {
        max = heap[rchild];
        maxIndex = rchild;
    }

    if (maxIndex != index) {
        swap(heap[maxIndex], heap[index]);
        HeapAdjust(heap, n, maxIndex);
    }
}

void BuildHeap(vector<int>& heap, int n) {
    if (heap.empty() || (int)heap.size()<n) { return; }
    for (int i=(n-2)/2; i>=0; --i) {
        HeapAdjust(heap, n, i);
    }
}

void heapSort(vector<int>& array) {
    if ((int)(array.size())<=1) { return; }

    BuildHeap(array, (int)array.size());
    for (int i=(int)array.size()-1; i>=0; --i) {
        swap(array.front(), array[i]);
        HeapAdjust(array, i, 0);
    }
}

void heapSort2(vector<int>& array) {
    if ((int)array.size()<=1) { return; }

    make_heap(array.begin(), array.end());
    for (int i=(int)array.size()-1; i>=0; --i) {
        pop_heap(array.begin(), array.begin()+i+1);
    }
}

int main(){
    vector<int> array = {8,6,9,4,2,3,2,0, -5, -3};
    heapSort2(array);
    for (int num:array) {
        printf("%d, ", num);
    }

    return 0;
}
