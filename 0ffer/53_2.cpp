class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // 二分法
        if(nums.back() == nums.size() - 1) return nums.back() + 1;
        int low = 0;
        int high = nums.size() - 1;
        int mid = high - (high - low) / 2;
        while(low <= high) {
            if(nums[mid] != mid) {
                high = mid - 1; 
            }else {
                low = mid + 1;
            }
            mid = high - (high - low) / 2;
        }
        

        return low; 
    }
};