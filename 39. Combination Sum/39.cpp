class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> temp;
        int sum = 0;
        sort(candidates.begin(), candidates.end());
        select(candidates, target, result, temp, sum, 0);
        return result;
    }

    void select(vector<int>& candidates, int target, vector<vector<int>>& result, vector<int> temp, int sum, int index) {
        for(int i = 0; i < candidates.size(); i++) {
            int c = candidates[i];
            if(i < index) {
                continue;
            }
            if(c + sum > target) {
                continue;
            }
            else if(c + sum == target) {
                temp.push_back(c);
                result.push_back(temp);
                return ;
            }else {
                temp.push_back(c);
                select(candidates, target, result, temp, c+sum, i);
                temp.pop_back();
            }
        }
    }
};