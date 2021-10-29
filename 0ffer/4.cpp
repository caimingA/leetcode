// 在一个 n * m 的二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
// 请完成一个高效的函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

/* 
    现有矩阵 matrix 如下：

    [
    [1,   4,  7, 11, 15],
    [2,   5,  8, 12, 19],
    [3,   6,  9, 16, 22],
    [10, 13, 14, 17, 24],
    [18, 21, 23, 26, 30]
    ]
    给定 target = 5，返回 true。

    给定 target = 20，返回 false。
*/

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        // m行， n列
        if(matrix.size() == 0) return false;
        int m = matrix.size();
        int n = matrix[0].size();

        // matrix[y][x]
        int y = m - 1; 
        int x = 0;
        while(x <= n - 1 && y >= 0) {
            if(matrix[y][x] == target) {
                return true;
            }else if(matrix[y][x] < target) {
                ++x;
            }else {
                --y;
            }
        }
        return false;
        
    }
};