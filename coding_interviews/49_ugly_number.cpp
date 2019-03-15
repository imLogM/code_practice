#include <iostream>

int getUgly(int index) {
    if (index <= 0) { return 0; }
    int* ugly = new int[index];
    ugly[0] = 1;
    int* pMul2 = &(ugly[0]);
    int* pMul3 = &(ugly[0]);
    int* pMul5 = &(ugly[0]);
    for (int i=1; i<index; ++i) {
        ugly[i] = std::min( std::min(*pMul2*2, *pMul3*3) , *pMul5*5 );
        while (*pMul2 * 2 <= ugly[i]) {
            ++pMul2;
        }
        while (*pMul3 * 3 <= ugly[i]) {
            ++pMul3;
        }
        while (*pMul5 * 5 <= ugly[i]) {
            ++pMul5;
        }
    }

    int res = ugly[index-1];
    delete[] ugly;
    return res;
}

int main(int argc, char** argv) {
    printf("%d", getUgly(9));
    return 0;
}
