//给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
//
//
//
//上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 感谢 Marcos 贡献此图。
//
//示例:
//
//输入: [0,1,0,2,1,0,1,3,2,1,2,1]
//输出: 6
//
class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() == 0) { return 0; }

        vector<int> leftMax(height.size(), 0), rightMax(height.size(), 0);
        for (int i=0; i<height.size(); ++i) {
            if (i==0) {
                leftMax[0] = height[0];
            } else {
                leftMax[i] = max(leftMax[i-1], height[i-1]);
            }
        }
        for (int i=height.size()-1; i>=0; --i) {
            if (i==height.size()-1) {
                rightMax[height.size()-1] = height[height.size()-1];
            } else {
                rightMax[i] = max(rightMax[i+1], height[i+1]);
            }
        }

        int ans = 0;
        for (int i=0; i<height.size(); ++i) {
            ans += max(0, min(leftMax[i], rightMax[i]) - height[i]);
        }

        return ans;
    }
};
