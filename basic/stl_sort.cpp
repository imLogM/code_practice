#include <iostream>
#include <vector>
#include <algorithm>

bool cmp_greater(int a, int b) {
    return a>b;
}

bool cmp_less(int a, int b) {
    return a<b;
}

int main(int argc, char** argv) {
    int array[] = {1,2,5,4,3};
    int length = sizeof(array)/sizeof(array[0]);

    std::sort(array, array+length, std::greater<int>());
    printf("greater的效果:\n");
    for (int i=0; i<length; ++i) {
        printf(" %d", array[i]);
    }
    printf("\n");

    std::sort(array, array+length, std::less<int>());
    printf("less的效果:\n");
    for (int i=0; i<length; ++i) {
        printf(" %d", array[i]);
    }
    printf("\n");

    std::sort(array, array+length, cmp_greater);
    printf("自定义greater的效果:\n");
    for (int i=0; i<length; ++i) {
        printf(" %d", array[i]);
    }
    printf("\n");

    std::sort(array, array+length, cmp_less);
    printf("自定义less的效果:\n");
    for (int i=0; i<length; ++i) {
        printf(" %d", array[i]);
    }
    printf("\n");

    return 0;
}