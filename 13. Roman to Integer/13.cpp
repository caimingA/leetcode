class Solution {
public:
    int romanToInt(string s) {
         map<char, int> temp = {
            {'I' , 1},
            {'V' , 5},
            {'X' , 10},
            {'L' , 50},
            {'C' , 100},
            {'D' , 500},
            {'M' , 1000}
        };
        int length = s.size();
        int result = 0;
        for(int i = 0; i < length; i++){
            if(temp[s[i]] < temp[s[i + 1]]){
                result -= temp[s[i]];
            }else{
                result += temp[s[i]];
            }
        }
        return result;
    }
    }
};