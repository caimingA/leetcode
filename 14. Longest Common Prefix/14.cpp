class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()){
            return "";
        }
        string result ="";
        for(int i = 0; i < strs[0].size(); i++){
            int com = strs[0][i];
            for(int j = 1; j < strs.size(); j++){
                if(strs[j][i] != com){
                    return result;
                }
            }
            result += com;
        }
        return result;
    }
};
