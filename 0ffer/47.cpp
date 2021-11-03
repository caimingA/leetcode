// 在一个 m*n 的棋盘的每一格都放有一个礼物，每个礼物都有一定的价值（价值大于 0）。
// 你可以从棋盘的左上角开始拿格子里的礼物，并每次向右或者向下移动一格、直到到达棋盘的右下角。
// 给定一个棋盘及其上面的礼物的价值，请计算你最多能拿到多少价值的礼物？


class Solution {
public:
    // dp
    int maxValue(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if(m == 0 && n == 0) return grid[0][0];
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                cout << dp[i][j] << endl;
                if(i == 0 && j == 0) {
                    dp[i][j] = grid[0][0];
                } else if(i == 0) {
                    dp[i][j] = grid[i][j] + dp[i][j - 1];
                } else if(j == 0) {
                    dp[i][j] = grid[i][j] + dp[i - 1][j];
                }else {
                    dp[i][j] = grid[i][j] + max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[m - 1][n - 1];
    }
    

    // 回溯法
    // int maxValue(vector<vector<int>>& grid) {
    //     int m = grid.size();
    //     int n = grid[0].size();

    //     cout << m << "---" << n << endl;

    //     if(m == 0 && n == 0) return grid[0][0];
    //     int sum = grid[0][0];
    //     int maxLength = grid[0][0];
    //     int y = 0;
    //     int x = 0;
    //     backtrack(grid, x, y, sum, maxLength, m, n);

    //     return maxLength;
    // }

    // void backtrack(vector<vector<int>>& grid, int x, int y, int sum, int& maxLength, int m, int n) {
    //     cout << "(" << x << "," << y << ") -> " << endl; 
    //     if(y == m - 1 && x == n - 1) {
    //         maxLength = max(maxLength, sum);
    //         return;
    //     }
    //     for(int i = 0; i < 2; ++i) {
    //         if(i == 0) {
    //             if(y < m - 1) {
    //                 backtrack(grid, x, y + 1, sum + grid[y+1][x], maxLength, m, n);
    //             }
    //         }else {
    //             if(x < n - 1) {
    //                 backtrack(grid, x + 1, y, sum + grid[y][x+1], maxLength, m, n);
    //             }
    //         }
    //     }
    // }
};

