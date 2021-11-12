class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> f(n+1,vector<int>(n+1));
        for (int i = n - 1; i >= 1; i--) {
            for (int j = i + 1; j <= n; j++) { // 从dp[n-1][n]由上往下算。dp[n-1][n]相当于算dp[n-1][n-1] = 0 和 dp[n][n] = 0的值
                int minCost = INT_MAX;
                for (int k = i; k < j; k++) {
                    int cost = k + max(f[i][k - 1], f[k + 1][j]);
                    minCost = min(minCost, cost);
                }
                f[i][j] = minCost;
            }
        }
        return f[1][n];

    }
};