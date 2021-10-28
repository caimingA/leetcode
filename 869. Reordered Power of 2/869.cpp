// 统计每个数字出现的频率，然后与2的幂进行对比
string countDigits(int n) { // 获取n的词频
    string count(10, '0');
    while (n) {
        // cout << count << endl;
        ++count[n % 10];
        n /= 10;
    }
    return count;
}
// unordered_set<string> recordPower2;
// int init = [](){ // lambda表达式 [实参]，(形参)。 这个地方相当于定义了一个int型的变量inti，然后用lambda函数进行赋值。但return 0， 所以inti最后为零
//     for(int i = 1; i <= 1e9; i <<= 1) {
//         cout << i << endl;
//         recordPower2.insert(countDigits(i));
//     }
//     return 0;
// }();        // (实参)

unordered_set <string> recordPower2;
int init = []() -> int {
    for(int i = 1; i <= 1e9; i <<= 1) {
        cout << i << endl;
        recordPower2.insert(countDigits(i));
    }
    return 0;
}(); 
// 其他的写法
// 1
// unordered_set <string> recordPower2 = [](){
//     unordered_set <string> tmp;
//     for(int i = 1; i <= 1e9; i <<= 1) {
//         cout << i << endl;
//         tmp.insert(countDigits(i));
//     }
//     return tmp;
// }();

// 2
// unordered_set <string> recordPower2 = []() -> unordered_set <string>{
//     unordered_set <string> tmp;
//     for(int i = 1; i <= 1e9; i <<= 1) {
//         cout << i << endl;
//         tmp.insert(countDigits(i));
//     }
//     return tmp;
// }();

class Solution {
public:
    bool reorderedPowerOf2(int n) {
        return recordPower2.count(countDigits(n));
    }
};



// 回溯 超时了
// class Solution {
// public:
//     bool reorderedPowerOf2(int n) {
//         // 单位数的判断
//         if(n == 1 || n == 2 || n == 4 || n == 8) return true;
        
        
//         // 得到组合
//         vector<int> num;
//         while(n) { // num: 低位 -> 高位
//             num.push_back(n % 10);
//             n = n / 10;
//         }

//         vector<vector<int>> result;
//         vector<int> temp;
//         vector<int> visit(num.size(), 0);


//         // 回溯算法
//         backTrack(result, temp, num, visit);
//         // 二乘幂的判断

//         for(auto oneSet : result) {
//             if(oneSet[0]%2 == 1 || oneSet[0] == 0) continue;
            
//             int oneNum = 0;
//             for(int i = 0; i < oneSet.size(); ++i) {
//                 oneNum += pow(10, i) * oneSet[i];
//             }
//             cout << oneNum << endl;

//             if(isPowerOfTwo(oneNum)) return true;
//         }

//         return false;

//     }

//     void backTrack(vector<vector<int>>& result, vector<int>& temp, vector<int> num, vector<int>& visit) {
//         if(temp.size() == num.size()) {
//             result.push_back(temp);
//             return ;
//         }
//         for(int i = 0; i < num.size(); ++i) {
//             if(visit[i] == 0) {
//                 temp.push_back(num[i]);
//                 visit[i] = 1;
//                 backTrack(result, temp, num, visit);

//                 temp.pop_back();
//                 visit[i] = 0;
//             }
//         }
//     }

//     bool isPowerOfTwo(int n) {
//         return (n & (n - 1)) == 0;
//     }
// };