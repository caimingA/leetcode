class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        if(nums.empty())
        {
            return 0;
        }
        int slow = 0;
        for(int quick = 0; quick < nums.size(); quick++)
        {
            if(nums[quick] == nums[slow])
            {
                continue;
            }
            else
            {
                slow++;
                nums[slow] = nums[quick];
            }
        }
        return slow + 1;
    }
};