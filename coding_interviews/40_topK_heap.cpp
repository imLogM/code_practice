#include <iostream>
#include <vector>
#include <algorithm>

class cmp_greater {     // less表示大顶堆，greater表示小顶堆
public:
    bool operator() (int a, int b) {
        return a > b;
    }
};

void getTopK(const std::vector<int>& data, std::vector<int>& topK, int k) {
    topK.clear();
    if (k<1 || data.empty()) {
        return;
    }

    for (int i=0; i<data.size(); ++i) {
        if (topK.size() < k) {
            topK.push_back(data[i]);
            std::push_heap(topK.begin(), topK.end(), cmp_greater());
            for (auto iter=topK.begin(); iter!=topK.end(); ++iter) {
                printf(" %d", *iter);
            }
            printf("\n");
        } else {
            if ( topK[0] < data[i] ) {
                std::pop_heap(topK.begin(), topK.end(), cmp_greater());
                topK.pop_back();
                topK.push_back(data[i]);
                std::push_heap(topK.begin(), topK.end(), cmp_greater());
            }
            for (auto iter=topK.begin(); iter!=topK.end(); ++iter) {
                printf(" %d", *iter);
            }
            printf("\n");
        }
    }
}

int main(int argc, char** argv) {
    std::vector<int> data = {1,2,9,3,4,7,5,9,6,8};
    std::vector<int> topK;
    getTopK(data, topK, 4);
    for (auto iter=topK.begin(); iter!=topK.end(); ++iter) {
        printf(" %d", *iter);
    }
    printf("\n");
    return 0;
}