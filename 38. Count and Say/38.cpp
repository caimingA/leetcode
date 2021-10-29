class Solution {
public:
    string countAndSay(int n) {
        string result = "1";
        if(n == 1){
            return result;
        }
        for(int i = 1; i < n; i++){
            string finResult = "";
            for(int j = 0; j < result.size(); ){
                int count = 0;
                int k = j;
                while(result[j] == result[k]){
                    count++;
                    k++;
                }
                finResult += to_string(count) + result[j];
                j = k;
            }
            result = finResult;
        }
        return result;
    }
};