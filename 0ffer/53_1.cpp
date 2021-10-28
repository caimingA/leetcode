class Solution {
public:
    int search(vector<int>& nums, int target) {
        unordered_map<int, int> record;
        for(auto num : nums) {
            auto it = record.find(num);
            if(it != record.end()) {
                ++record[num];
            }else {
                record[num] = 1;
            }
        }

        auto it = record.find(target);
        if(it != record.end()) {
            return record[target];
        }else {
            return 0;
        }
    }
};