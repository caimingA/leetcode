// 输入一个整型数组，数组中的一个或连续多个整数组成一个子数组。求所有子数组的和的最大值。

// 要求时间复杂度为O(n)。

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int now = 0;
        int maxNums = nums[0];
        for(int num : nums) {
            now = max(now + num, num);
            maxNums = max(maxNums, now);
        }

        return maxNums;
    }
};