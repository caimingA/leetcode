// 给定一个数字，我们按照如下规则把它翻译为字符串：0 翻译成 “a” ，1 翻译成 “b”，……，11 翻译成 “l”，……，25 翻译成 “z”。一个数字可能有多个翻译。请编程实现一个函数，用来计算一个数字有多少种不同的翻译方法。


class Solution {
public:
    int translateNum(int num) {
        int a = 0;
        int b = 0;
        int c = 0;
        if(num == 0) return 1;
        vector<int> nums;
        
        while(num){
            nums.push_back(num%10);
            num = num / 10;
        }
        reverse(nums.begin(), nums.end());
        cout << nums[0] << endl;
        if(nums.size() == 1) return 1;
        a = 1;
        if((nums[0] == 1 || nums[0] == 2) && nums[0]*10+nums[1] <= 25) {
            b = 2;
        }else {
            b = 1;
        }

        if(nums.size() == 2) return b;
        for(int i = 2; i < nums.size(); ++i) {
            // a是i-2，b是i-1，c是i
            if((nums[i-1] == 1 || nums[i-1] == 2) && nums[i-1]*10+nums[i] <= 25) {
                c = b + a;
            }else {
                c = b;
            }

            a = b;
            b = c;
        }
        return b;

    }
};