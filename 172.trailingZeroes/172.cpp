class Solution {
public:
    int trailingZeroes(int n) { //只需要判断有几个5的因子
        if(n == 0){
            return 0;
        }
        int count = 0;
        int num = 0;
        for(int i = 0; i < n; i++){
            if((i+1)%5 == 0){
                num = i + 1;
                while(num % 5 == 0){
                    count++;
                    num /= 5;
                }
            }
        }
        return count;
    }
};

// 5的阶乘的话肯定只出现一个5，10的阶乘出现两个5.
// 25的阶乘会出现6个5，其中25包含两个5.可以先让25/5=5计算一个5，然后再算一个5
// public int trailingZeroes(int n) {
//     int count = 0;
//     while (n > 0) {
//         count += n / 5;
//         n = n / 5;
//     }
//     return count;
// }