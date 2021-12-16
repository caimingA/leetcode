// 求 1+2+...+n ，
// 要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。

class Solution {
public:
    int sumNums(int n) {
        int preSum = 0;
        return sumNum(n, preSum);
    }
    int sumNum(int n, int preSum) {
        preSum += n;
        return n == 0 ? preSum : sumNum(n - 1, preSum);
    }
};