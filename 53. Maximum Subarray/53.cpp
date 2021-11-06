class Solution {
public:
    int max(int a, int b){
        return a>b ? a : b;
    }
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        if(size == 1){
            return nums[0];
        }
        vector<int> dp(size);
        dp[0] = nums[0];
        int maxNum = nums[0];
        for(int i = 1; i < size; i++){
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            if(dp[i] > maxNum){
                maxNum = dp[i];
            }
        }
        return maxNum;
    }
};



