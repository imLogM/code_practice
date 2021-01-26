// p2、p20
// 有放回地从长度为n的数组ks中取出4个数，使其和为m。判断是否存在。
// 1<=n<=1000
// 1<=m<=10e8
// 1<=k<=10e8


#include <cstdio>
#include <vector>
#include <algorithm>


using namespace std;

class Solution
{
public:
    static bool solve(const int m, const vector<int>& ks) {

        // 解法：要使a+b+c+d=m，穷举a、b，二分查找c+d的值

        // 穷举c+d的值，并排序
        vector<int> kk(ks.size()*ks.size());
        for (int i=0; i<ks.size(); ++i) {
            for (int j=0; j<ks.size(); ++j) {
                kk[i*ks.size()+j] = ks[i] + ks[j];
            }
        }
        sort(kk.begin(), kk.end());

        // 穷举 a、b
        for (int i=0; i<ks.size(); ++i) {
            for (int j=0; j<ks.size(); ++j) {
                int target = m-ks[i]-ks[j];
                if (binSearch(kk, target)) {
                    return true;
                }
            }
        }

        return false;
    }
    static bool binSearch(const vector<int>& v, const int target) {
        int lo = 0, hi = v.size();
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (target < v[mid]) {
                hi = mid;
            } else if (target > v[mid]) {
                lo = mid + 1;
            } else {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    int m=10;
    vector<int> ks={1,3,5};
    printf("res=%d\n", Solution::solve(m, ks));
    m = 9;
    printf("res=%d\n", Solution::solve(m, ks));
    return 0;
}
