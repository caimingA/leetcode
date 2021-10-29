class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // m行，n列
        int m = matrix.size();
        int n = matrix[0].size();

        int x = 0; // 列坐标
        int y = m - 1;     // 行坐标

        while(x <= n - 1 && y >= 0) {
            if(matrix[y][x] == target) return true;
            else if(matrix[y][x] > target) --y; // 现在的点大于target的时候，说明这一行都不可能有target
            else ++x; // 现在的点小于target的时候，说明这一列都不可能有target
        }
        return false;
    }

    // 二分法 O(m * log n)
    // bool binarySearch(vector<int> row, int target) {
    //     int low = 0;
    //     int high = row.size() - 1;
    //     while(low <= high) {
    //         int mid = (low + high) / 2;
    //         if(row[mid] == target) {
    //             return true;
    //         }else if(row[mid] > target) {
    //             high = mid - 1;
    //         }else {
    //             low = mid + 1;
    //         }
    //     }
    //     return false;
    // }

    // bool searchMatrix(vector<vector<int>>& matrix, int target) {
    //     // m行，n列
    //     for(auto col : matrix) {
    //         bool flag = binarySearch(col, target);
    //         if(flag) return true;
    //     }
    //     return false;
    // }

    // 用lower_bound
    // bool searchMatrix(vector<vector<int>>& matrix, int target) {
    //     for (const auto& row: matrix) {
    //         auto it = lower_bound(row.begin(), row.end(), target);
    //         if (it != row.end() && *it == target) {
    //             return true;
    //         }
    //     }
    //     return false;
    // }

};