class Solution {
public:
    int lengthOfLastWord(string s) {
        // s.reserve();
        int result = 0;
        int lenght = s.size();
        int spaceNum = 0;
        for(int i = lenght - 1; i >= 0; i--){
            if(s[i] != ' '){
                break;
            }
            ++spaceNum;
        }
        for(int i = lenght - spaceNum - 1; i >= 0; i--){
            if(s[i] == ' '){
                return result;
            }
            ++result;
        }
        return result;
    }
};