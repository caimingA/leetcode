class Solution {
public:
    int titleToNumber(string s) {
        int result = 0;
        reverse(s.begin(), s.end());
        int size =  s.size();
        for(int i = 0; i < size; i++){
            // cout << s[i] << endl;
            result += pow(26, i) * (s[i] - 'A' + 1);
            // cout << pow(26, i);
        }
        return result;
    }
};