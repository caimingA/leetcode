class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> trace;
        traceback(result, trace, nums);
        return result;
    }
    void traceback(vector<vector<int>>& result, vector<int>& trace, vector<int> nums){
        int numLength = nums.size();
        int traceLength = trace.size();
        if(numLength == traceLength){
            result.push_back(trace);
            return ;
        }
        for(int i = 0; i < numLength; i++){
            if(find(trace.begin(), trace.end(), nums[i]) != trace.end()){
                continue;
            }
            trace.push_back(nums[i]);
            traceback(result, trace, nums);
            trace.pop_back(); 
        }

    }
};