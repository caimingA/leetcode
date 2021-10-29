// 在字符串 s 中找出第一个只出现一次的字符。如果没有，返回一个单空格。 s 只包含小写字母。

class Solution {
public:
    char firstUniqChar(string s) {
        if(s == "") return ' ';
        unordered_map<char, int> hashmap;
        // map<char, int> hashmap;
        for(char c : s) {
            if(hashmap.find(c) == hashmap.end()) {
                hashmap.insert(pair<char, int>(c, 1));
            }else {
                ++hashmap[c];
            }
        }
        for(char c : s) {
            if(hashmap[c] == 1) return c;
        }
        return ' ';
    }
};