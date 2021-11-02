// 青蛙跳台阶

class Solution {
public:
    int numWays(int n) {
        if(n == 0) return 1;
        if(n == 1) return 1;
        if(n == 2) return 2;
        int i = 2;

        int a = 1;
        int b = 2;
        int c = 0;
        while(i < n) {
            c = (a + b) % 1000000007;
            a = b;
            b = c;
            c = 0;
            
            ++i;
        }
        return b;

    }
};