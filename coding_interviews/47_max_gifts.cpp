#include <iostream>

int getMaxGifts(const int* matrix, int rows, int cols) {
    if (matrix == nullptr || rows <= 0 || cols <= 0) {
        return 0;
    }

    int* maxGifts = new int[rows*cols];
    for (int i=0; i<rows*cols; ++i) {
        maxGifts[i] = 0;
    }

    int up = 0;
    int left = 0;
    for (int x=0; x<rows; ++x) {
        for (int y=0; y<cols; ++y) {
            up = 0;
            left = 0;
            if (x>0) { up = maxGifts[(x-1)*cols+y]; }
            if (y>0) { left = maxGifts[x*cols+y-1]; }
            maxGifts[x*cols+y] = std::max(up, left) + matrix[x*cols+y];
        }
    }

    int res = maxGifts[rows*cols-1];
    delete[] maxGifts;
    return res;
}

int main(int argc, char** argv) {
    int array[4][4] = {1,10,3,8,12,2,9,6,5,7,4,11,3,7,16,5};
    printf("%d\n", getMaxGifts((int*)array, 4, 4));
    return 0;
}
