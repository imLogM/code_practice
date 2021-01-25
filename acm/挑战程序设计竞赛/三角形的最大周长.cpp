// p16
// 有n根棍子，棍子i的长度为ai。想要从中选出3根棍子组成周长尽可能常的三角形，请输出最大的周长。若无法组成三角形，则输出0。
// 限制条件：3<=n<=100, 1<=ai<=10^6

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    static int getMaxTrianglePerimeter(vector<int> stickLens) {
        // if (stickLens.size() < 3) { return 0; }

        std::sort(stickLens.begin(), stickLens.end(), std::greater<int>());  //从大到小
        for (int i=0; i+2<stickLens.size(); ++i) {
            if (stickLens[i] < stickLens[i+1] + stickLens[i+2]) {
                return stickLens[i] + stickLens[i+1] + stickLens[i+2];
            }
        }
        return 0;
    }
};

int main()
{
    vector<int> stickLens = {2,3,4,5,10};
    printf("%d\n", Solution::getMaxTrianglePerimeter(stickLens));
    stickLens = vector<int>({4,5,10,20});
    printf("%d\n", Solution::getMaxTrianglePerimeter(stickLens));
    return 0;
}