class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.empty()){
            return 0;
        }
        // int result = 0;
        int length = nums.size();
        for(int i = 0; i < length; i++){
            if(target <= nums[i]){
                return i;
            }
        }
        return length;
    }
};