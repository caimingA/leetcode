class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> result;

        unordered_map<int, int> hashmap;
        for(int num : nums) {
            if(hashmap.count(num) != 0) {
                ++hashmap[num];
            }else {
                hashmap[num] = 1;
            }
        }
        for(auto it : hashmap) {
            if(it.second == 1) {
                result.push_back(it.first);
            }
        }
        return result;
    }
};