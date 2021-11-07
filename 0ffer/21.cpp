// 输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有奇数在数组的前半部分，所有偶数在数组的后半部分。

class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int i = 0;
        int j = nums.size() - 1;
        while(i < j) {
            if(nums[i] % 2 == 0 && nums[j] % 2 == 1) {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }else if(nums[i] % 2 == 0){
                --j;
            }else if(nums[j] % 2 == 1) {
                ++i;
            }else {
                ++i;
                --j;
            }
        }
        return nums;
    }
};