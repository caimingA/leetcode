// 斐波那契数列

class Solution {
public:
    int fib(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;

        int a = 0;
        int b = 1;

        int i = 1;
        while(i < n) {
            int temp = a;
            a = b;
            b = (a + temp) % 1000000007;
            ++i;
        }
        return b;
    }
};