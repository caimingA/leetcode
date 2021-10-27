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

    // 队列
    // vector<string> letterCombinations(string digits) {
    //     vector<string> result;
    //     queue<string> tmp;
    //     int lenght = digits.size();
    //     if(!lenght){
    //         return result;
    //     }

    //     unordered_map<char, string> M = {
    //         {'2', "abc"},
    //         {'3', "def"},
    //         {'4', "ghi"},
    //         {'5', "jkl"},
    //         {'6', "mno"},
    //         {'7', "pqrs"},
    //         {'8', "tuv"},
    //         {'9', "wxyz"}
    //     };
    //     string track = "";
    //     int i = 0;
    //     for(char digit : digits){
    //         string selection = M[digit];
    //         if(i==0){
    //             for(char letter : selection){
    //                 track = letter;
    //                 tmp.push(track);
    //             }
    //         }else{
    //             int num = tmp.size();
    //             for(int j = 0; j < num; j++){
    //                 track = tmp.front();
    //                 tmp.pop();
    //                 for(char letter : selection){
    //                     track.push_back(letter);
    //                     tmp.push(track);
    //                     track.pop_back();
    //                 }
    //             }
    //         }
    //         i++;
    //     }
    //     while(!tmp.empty()){
    //         track = tmp.front();
    //         tmp.pop();
    //         result.push_back(track);
    //     }
    //     return result;
    // }
};