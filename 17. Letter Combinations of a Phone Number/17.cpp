class Solution {
public:
    
    // 队列
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        queue<string> tmp;
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
        int i = 0;
        for(char digit : digits){
            string selection = M[digit];
            if(i==0){
                for(char letter : selection){
                    track = letter;
                    tmp.push(track);
                }
            }else{
                int num = tmp.size();
                for(int j = 0; j < num; j++){
                    track = tmp.front();
                    tmp.pop();
                    for(char letter : selection){
                        track.push_back(letter);
                        tmp.push(track);
                        track.pop_back();
                    }
                }
            }
            i++;
        }
        while(!tmp.empty()){
            track = tmp.front();
            tmp.pop();
            result.push_back(track);
        }
        return result;
    }
};