// 输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。为简单起见，标点符号和普通字母一样处理。
// 例如输入字符串"I am a student. "，则输出"student. a am I"。

class Solution {
public:
    string reverseWords(string s) {
        if(s.size() == 0) return "";
        int i = 0;
        int j = s.size() - 1;
        int k = 0;
        cout << i << " and " << j << endl;
        while(s[i] == ' ' && i <= s.size() - 1) {
            ++i;
        }
        cout << i << endl;
        while(j >= 0) {
            if(s[j] == ' ') {
                --j;
            } else {
                break;
            }
        }
        cout << j << endl;

        
        if(i > j) return "";

        k = j;
        string temp = "";
        string res = "";
        int flag = 1;
        while(k != i - 1) {
            // cout << temp << endl;
            if(flag) {
                if(s[k] != ' '){
                    temp = s[k] + temp;
                }else {
                    // cout << "-----------------" << endl;
                    flag = 0;
                    res = res + temp + " ";
                    cout << temp<< endl;
                    temp = "";
                }
            }else {
                if(s[k] != ' ') {
                    flag = 1;
                    j = k;
                    temp = s[k] + temp;
                }
            }
            --k;
        }
        cout << res + temp;
        return res + temp;

    }
};