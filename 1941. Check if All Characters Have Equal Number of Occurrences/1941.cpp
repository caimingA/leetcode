class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char, int> hashmap;
        for(char c : s) {
            if(hashmap.find(c) == hashmap.end()) {
                hashmap[c] = 1;
            }else {
                ++hashmap[c];
            }
        }
        int num = 0;
        for(auto it : hashmap) {
            if(num == 0) {
                num = it.second;
            }else {
                if(num != it.second) return false;
            }
        }
        return true;
    }
};