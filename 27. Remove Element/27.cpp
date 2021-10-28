class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // for(int i = 0; i < nums.size(); i++){
        //     if(nums[i] == val){
        //         nums.erase(nums.begin() + i);
        //         --i;
        //     }
        // }
        // return nums.size();
        int i = 0;
        int j = 0;
        int length = nums.size();
        while(j < length){
            if(nums[j] != val){
                nums[i] = nums[j];
                ++i;    
            }
            ++j;
        }
        return i;
    }
};