class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        if(n == 0) return result;
        string trace = "";
        traceback(n, trace, result, 0, 0);
        return result;
    }
    void traceback(int n, string& trace, vector<string>& result, int left, int differ){
        if(2*n == trace.size()){
            result.push_back(trace);
            return ;
        }
        for(int i = 0; i < 2; i++){ //可选择的数量
            if(differ == 0){
                trace.push_back('(');
                traceback(n, trace, result, left+1, 1);
                i++;
            }else if(left == n){
                trace.push_back(')');
                traceback(n, trace, result, left, differ-1);
                i++;
            }else{
                if(i == 0){
                    trace.push_back('(');
                    traceback(n, trace, result, left+1, differ+1);
                }else{
                    trace.push_back(')');
                    traceback(n, trace, result, left, differ-1);
                }
            }
            trace.pop_back();
        }

    }
};