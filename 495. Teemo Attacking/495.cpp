class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int time = 0;
        for(int i = 0; i < timeSeries.size(); ++i) {
            if(i == 0) continue;

            if(timeSeries[i] - timeSeries[i - 1] >= duration) {
                time += duration;
            }else {
                time += timeSeries[i] - timeSeries[i - 1];
            }
        }
        
        return time + duration;
    }
};