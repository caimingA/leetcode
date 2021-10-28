class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_set<int> record;
        for(auto num : nums) {
            if(record.count(num)){
                return num;
            }else{
                record.insert(num);
            }
        } 
        return 0;
    }
};