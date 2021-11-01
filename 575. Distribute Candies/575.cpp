class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int>record(candyType.begin(), candyType.end());

        return record.size() > candyType.size()/2 ? candyType.size() / 2: record.size();

    }
};