// 从若干副扑克牌中随机抽 5 张牌，判断是不是一个顺子，即这5张牌是不是连续的。2～10为数字本身，A为1，J为11，Q为12，K为13，而大、小王为 0 ，可以看成任意数字。A 不能视为 14。

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