// 输入一个非负整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。

// class Solution {
// public:
//     string minNumber(vector<int>& nums) {
//         vector<string> strs;
//         for(int i = 0; i < nums.size(); i++)
//             strs.push_back(to_string(nums[i]));
//         quickSort(strs, 0, strs.size() - 1);
//         string res;
//         for(string s : strs)
//             res.append(s);
//         return res;
//     }
// private:
//     void quickSort(vector<string>& strs, int l, int r) {
//         if(l >= r) return;
//         int i = l, j = r;
//         while(i < j) {
//             while(strs[j] + strs[l] >= strs[l] + strs[j] && i < j) j--;
//             while(strs[i] + strs[l] <= strs[l] + strs[i] && i < j) i++;
//             swap(strs[i], strs[j]);
//         }
//         swap(strs[i], strs[l]);
//         quickSort(strs, l, i - 1);
//         quickSort(strs, i + 1, r);
//     }
// };

class Solution {
public:
    string minNumber(vector<int>& nums) {
        vector<string> strs;
        string res;
        for(int i = 0; i < nums.size(); i++)
            strs.push_back(to_string(nums[i]));
        sort(strs.begin(), strs.end(), [](string& x, string& y){ return x + y < y + x; });
        for(int i = 0; i < strs.size(); i++)
            res.append(strs[i]);
        return res;
    }
};


// sort 的lamda使用
// class Solution {
// public:
//     string minNumber(vector<int>& nums) {
//         sort(nums.begin(), nums.end(), [](int x, int y) {return x > y;});
//         for(int num : nums) {
//             cout << num << endl;
//         }
        
//         return "";
//     }
// };