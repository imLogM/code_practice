#include <iostream>
#include <vector>
#include <set>

class cmp_less {
public:
    bool operator() (int a, int b) {
        return a < b;
    }
};


void getTopK(const std::vector<int>& data, std::multiset<int, cmp_less>& topK, int k) {
    topK.clear();
    if (k<1 || data.empty()) {
        return;
    }

    for (int i=0; i<data.size(); ++i) {
        if (topK.size() < k) {
            topK.insert(data[i]);
        } else {
            if ( *(topK.begin()) < data[i] ) {
                topK.erase( topK.begin() );
                topK.insert(data[i]);
            }
        }
    }
}

int main(int argc, char** argv) {
    std::vector<int> data = {1,2,9,3,4,7,5,9,6,8};
    std::multiset<int, cmp_less> topK;
    getTopK(data, topK, 4);
    for (auto iter=topK.begin(); iter!=topK.end(); ++iter) {
        printf(" %d", *iter);
    }
    printf("\n");
    return 0;
}