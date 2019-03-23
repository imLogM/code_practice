#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    Solution(vector<int> nums) {
        _elem = nums;
        // srand((unsigned int)time(NULL));
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return _elem;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> shuffle = _elem;
        for (int i=shuffle.size()-1; i>=0; ++i) {
            int r = rand() % (i+1);
            swap(shuffle[r], shuffle[i]);
        }
        return shuffle;
    }
private:
    vector<int> _elem;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */

int main(int argc, char** argv) {
    vector<int> nums = {1,2,3};
    Solution* obj = new Solution(nums);
    vector<int> param_1 = obj->reset();
    vector<int> param_2 = obj->shuffle();
}
