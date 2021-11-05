class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int result = 0;
        unordered_map<int, int> hashmap;
        for(int num : arr) {
            hashmap[num] = hashmap[num - difference] + 1; // 不在map的直接返0
            cout << hashmap[num - difference] << endl;
            result = max(hashmap[num], result);
        }
        return result;
    }
}; 