//给一个无序数组，要求奇数放左边，偶数放右边。

#include <iostream>
#include <vector>

using namespace std;

void separator_odd_even(vector<int>& array) {
    if (array.empty()) { return; }

    int i=0, j=array.size()-1;
    while (i < j) {
        while (i<j && array[i]%2==1) {
            ++i;
        }
        swap(array[i], array[j]);
        while (i<j && array[j]%2==0) {
            --j;
        }
        swap(array[i], array[j]);
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    vector<int> array;
    int temp;
    for (int i=0; i<n; ++i) {
        scanf("%d", &temp);
        array.push_back(temp);
    }

    separator_odd_even(array);

    for (int num : array) {
        printf("%d, ", num);
    }
    printf("\n");

    return 0;
}
