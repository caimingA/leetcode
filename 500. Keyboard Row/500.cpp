class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> res;
        if(words.size() == 0) return res;

        string ss1 = "qwertyuiopQWERTYUIOP";
        string ss2 = "asdfghjklASDFGHJKL";
        string ss3 = "zxcvbnmZXCVBNM";
        int now = 0;
        int pre = 0;
        int flag = 1;
        for(string word : words) {
            int size = word.size();
            cout << "++++++++ " << word << " ++++++++" << endl;
            for(int i = 0; i < size; ++i) {
                if(i == 0) {
                    if(ss1.find(word[i]) != string::npos) {
                        now = 1;
                    }else if(ss2.find(word[i]) != string::npos) {
                        now = 2;
                    }else {
                        now = 3;
                    }
                    cout << "char: " << word[i] << " pre = " << pre << " now = " << now << endl;
                }else {
                    pre = now;
                    if(ss1.find(word[i]) != string::npos) {
                        now = 1;
                    }else if(ss2.find(word[i]) != string::npos) {
                        now = 2;
                    }else {
                        now = 3;
                    }
                    cout << "char: " << word[i] << " pre = " << pre << " now = " << now << endl;
                    if(pre != now) {
                        flag = 0;
                        break;
                    }
                }
            }
        if(flag) {
            res.push_back(word);
        }
        flag = 1;
        pre = 0;
        now = 0;

        }
        return res;
    }
};