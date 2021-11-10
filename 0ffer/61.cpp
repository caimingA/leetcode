

class Solution {
public:
    bool isStraight(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int count = 0;
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] == 0) {
                ++count;
            }else {
                if(i == 0) {
                    continue;
                }
                if(nums[i - 1] == 0) {
                    continue;
                }
                if(nums[i]- nums[i - 1]  == 1) {
                    continue;
                }else if(nums[i]- nums[i - 1]  == 0) {
                    return false;
                }else {
                    if(nums[i] - nums[i - 1] - 1 <= count) {
                        count -= (nums[i] - nums[i - 1] - 1);
                    }else {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};