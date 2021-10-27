class Solution {
public:
    int romanToInt(string s) {
         int length = s.size();
        int sum = 0;
        for(int i = 0; i < length; i++){
            if(s[i] == 'I' && (s[i + 1] == 'V' || s[i + 1] == 'X')){
                sum -= 2;
            }else if(s[i] == 'X' && (s[i + 1] == 'L' || s[i + 1] == 'C')){
                sum -= 20;
            }else if(s[i] == 'C' && (s[i + 1] == 'D' || s[i + 1] == 'M')){
                sum -= 200;
            }
        }
        for(int i = 0; i < length; i++){
            if(s[i] == 'I'){
                sum += 1;
            }else if(s[i] == 'V'){
                sum += 5;
            }else if(s[i] == 'X'){
                sum += 10;
            }else if(s[i] == 'L'){
                sum += 50;
            }else if(s[i] == 'C'){
                sum += 100;
            }else if(s[i] == 'D'){
                sum += 500;
            }else{
                sum += 1000;
            }
        }
        return sum;
    }
};