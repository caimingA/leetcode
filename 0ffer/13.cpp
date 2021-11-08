// 地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。
// 一个机器人从坐标 [0, 0] 的格子开始移动，它每次可以向左、右、上、下移动一格（不能移动到方格外），也不能进入行坐标和列坐标的数位之和大于k的格子。
// 例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。
// 但它不能进入方格 [35, 38]，因为3+5+3+8=19。请问该机器人能够到达多少个格子？


class Solution {
public:

    
    int getSumAxis(int x, int y) {
        int res = 0;
        while(x) {
            res += x % 10;
            x /= 10;
        }
        while(y) {
            res += y % 10;
            y /= 10;
        }
        return res;
    }

    void BFS(int y, int x, vector<vector<int>>& vis, int k, int& res) {
        queue<vector<int>> q;
        vector<int> root = {x, y};
        q.push(root);
        vis[y][x] = 1;
        while(!q.empty()) {
            int nowX = q.front()[0];
            int nowY = q.front()[1];

            q.pop();
            ++res;
            cout << nowX << " and " << nowY << endl;
            if(nowY+1 < vis.size()) {
                if(vis[nowY+1][nowX] == 0 && getSumAxis(nowY+1, nowX) <= k) {
                    vector<int> newPoint = {nowX, nowY+1};
                    vis[newPoint[1]][newPoint[0]] = 1;
                    cout << " |_ " << newPoint[0] << " || " << newPoint[1] << endl;
                    q.push(newPoint);
                }
            }
            if(nowX+1 < vis[0].size()) {
                if(vis[nowY][nowX+1] == 0 && getSumAxis(nowY,nowX+1) <= k) {
                    vector<int> newPoint = {nowX+1, nowY};
                    vis[newPoint[1]][newPoint[0]] = 1;
                    cout << " |_ " << newPoint[0] << " || " << newPoint[1] << endl;
                    q.push(newPoint);
                }
            }
        }
    }
    
    int movingCount(int m, int n, int k) {
        // m行 n列
        
        if(k == 0) return 1;
        vector<vector<int>> vis (m, vector<int> (n, 0)); 
        int res = 0;
        cout << "********up**********" << endl;
        BFS(0, 0, vis, k, res);
        cout << "*******down*********" << endl;
        return res;
    }
        
};


// 递推
class Solution {
    int get(int x) {
        int res=0;
        for (; x; x /= 10){
            res += x % 10;
        }
        return res;
    }
public:
    int movingCount(int m, int n, int k) {
        if (!k) return 1;
        vector<vector<int> > vis(m, vector<int>(n, 0));
        int ans = 1;
        vis[0][0] = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if ((i == 0 && j == 0) || get(i) + get(j) > k) continue;
                // 边界判断
                if (i - 1 >= 0) vis[i][j] |= vis[i - 1][j];
                if (j - 1 >= 0) vis[i][j] |= vis[i][j - 1];
                ans += vis[i][j];
            }
        }
        return ans;
    }
};