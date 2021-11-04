// 请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子字符串的长度。

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> hashmap;
        int length = 0;
        int maxLength = 0;
        for(int i = 0; i < s.size(); ++i) {
            auto it = hashmap.find(s[i]);
            if(it == hashmap.end()) {
                ++length;
                hashmap[s[i]] = i;
            }else {
                int j = hashmap[s[i]];
                if(i - j > length) {
                    ++length;
                    hashmap[s[i]] = i;
                }else {
                    length = i - j;
                    hashmap[s[i]] = i;
                }
            }
            // cout << s[i] << " === " << maxLength << " === " << length << endl;
            maxLength = max(length, maxLength);
        }

        // for(auto it : hashmap) {
        //     cout << it.first << " in " << it.second << endl;
        // }
        return maxLength;
    }
};