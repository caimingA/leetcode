// 把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
// 输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。
// 例如，数组 [3,4,5,1,2] 为 [1,2,3,4,5] 的一个旋转，该数组的最小值为1。


class Solution {
public:
    int minArray(vector<int>& numbers) {
        if(numbers.size() == 1) return numbers[0];
        for(int i = 1; i < numbers.size(); ++i) {
            // cout << numbers[i] << endl;
            if(numbers[i] < numbers[i - 1]) return numbers[i];
        }
        return numbers[0];
    }
};