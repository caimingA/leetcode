class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, int> secretMap;
        unordered_map<char, int> guessMap;
        int bull = 0;
        for(int i = 0; i < secret.size(); ++i) {
            if(secret[i] == guess[i]) {
                ++bull;
            }
            ++secretMap[secret[i]];
            ++guessMap[guess[i]];
        }
        int cow = 0;
        for(auto it : secretMap) {
            if(guessMap.find(it.first) != guessMap.end()) { // 都有这些元素
                cow += min(guessMap[it.first], it.second);
            }
        }
        cow -= bull;
        string res = to_string(bull) + 'A' + to_string(cow) + 'B';
        return res;
    }
};