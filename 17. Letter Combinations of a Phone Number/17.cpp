class Solution {
public:
    
    // 回溯
    void backtrack(vector<string>& result, unordered_map<char, string> M, int lenght, int i, string& track, string digits){
        if(i == lenght){ 
            result.push_back(track);
        }else{
            char digit = digits[i];
            string selection = M[digit];

            for(int j = 0; j < selection.size(); j++){
                track.push_back(selection[j]);
                cout << track << endl;
                backtrack(result, M, lenght, i+1, track, digits);
                track.pop_back();
            }
        }
        
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        int lenght = digits.size();
        if(!lenght){
            return result;
        }

        unordered_map<char, string> M = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        string track = "";
        backtrack(result, M, lenght, 0, track, digits);
        return result;
    }
};