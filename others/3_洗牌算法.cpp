#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

bool shuffle(vector<int>& array) {
    if (array.empty()) { return true; }

    srand((unsigned int)time(NULL));
    for (int i=array.size()-1; i>=0; --i) {
        int swapIndex = rand() % (i+1);
        swap(array[i], array[swapIndex]);
    }
    return true;
}

int main()
{
    vector<int> array = {1,2,3,4,5};
    shuffle(array);
    for (int v : array) {
        printf("%d,", v);
    }
    printf("\n");
    return 0;
}
