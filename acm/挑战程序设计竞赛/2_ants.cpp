// p18
// n只蚂蚁以每秒1cm的速度在长为L cm的杆子上爬行。当蚂蚁爬到杆子端点时就会掉落。由于杆子太细，两只蚂蚁相遇时，只能各自反向爬回去。
// 对于每只蚂蚁，我们知道它距离杆子左端的距离x，但不知道它现在的朝向。请计算所有蚂蚁落下杆子所需的最短时间和最长时间。
// 1<= L <= 10e6
// 1<= n <= 10e6
// 0<= x <= L

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    static pair<int, int> getAntsMinAndMaxTime(const int L, const vector<int>& xs) {
        // assert x<L && L>0

        int minT = 0, maxT = 0;
        for (int x : xs) {
            minT = max(minT, min(x, L-x));
            maxT = max(maxT, max(x, L-x));
        }
        return {minT, maxT};
    }
};

int main()
{
    int L=10;
    vector<int> xs={2,6,7};
    auto minMaxT = Solution::getAntsMinAndMaxTime(L, xs);
    int minT = minMaxT.first;
    int maxT = minMaxT.second;
    printf("minT=%d,maxT=%d\n", minT, maxT);
    return 0;
}
