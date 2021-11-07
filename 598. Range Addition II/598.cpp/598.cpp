class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        
        if(ops.empty()) return m*n;

        int rows = ops.size();
        int cols = ops[0].size();

        int count = 0;
        int y = INT_MAX;
        int x = INT_MAX;
        for(int i = 0; i < rows; ++i) {
            ++count;
            y = min(y, ops[i][0]);
            x = min(x, ops[i][1]);
        }
        return x*y;
        return 0;
    }
};