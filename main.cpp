#include <cstdio>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int topK(vector<int>& nums1, int bg1, int ed1, vector<int>& nums2, int bg2, int ed2, int k) {
        int len1 = ed1-bg1;
        int len2 = ed2-bg2;

        if (k > len1 + len2 || k <= 0) {
            cout << "error k\n";
            return 0;
        }

        if (len1==0) {
            return nums2[bg2+k-1];
        }
        if (len1 > len2) {
            return topK(nums2, bg2, ed2, nums1, bg1, ed1, k);
        } else if (k==1) {
            return min(nums1[bg1], nums2[bg2]);
        }

        int mid1 = ((len1 > k/2)? k/2 : len1);
        int mid2 = (k - mid1);
        if (nums1[bg1+mid1-1] > nums2[bg2+mid2-1]) {
            return topK(nums1, bg1, ed1, nums2, bg2+mid2, ed2, k-mid2);
        } else if (nums1[bg1+mid1-1] < nums2[bg2+mid2-1]) {
            return topK(nums1, bg1+mid1, ed1, nums2, bg2, ed2, k-mid1);
        } else {
            return nums1[bg1+mid1-1];
        }

    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = (int)nums1.size();
        int len2 = (int)nums2.size();
        if (nums1.empty() && nums2.empty()) { return 0; }

        int m1 = (len1+len2+1) / 2;
        int m2 = (len1+len2+2) / 2;
        return 0.5*(topK(nums1, 0, len1, nums2, 0, len2, m1)+topK(nums1, 0, len1, nums2, 0, len2, m2));
    }
};

int main() {
    vector<int> nums1({1,3});
    vector<int> nums2({2});
    Solution s;
    cout << s.findMedianSortedArrays(nums1, nums2) << endl;

    return 0;
}
