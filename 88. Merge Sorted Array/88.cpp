class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> result;
        if(n == 0) {
            nums1 = nums1;
            return;
        }
        if(m == 0) {
            nums1 = nums2;
            return;
        }
        
        int i = 0;
        int j = 0;
        while(i < m && j < n){
            if(nums1[i] < nums2[j]){
                result.push_back(nums1[i]);
                i++;
            }else{
                result.push_back(nums2[j]);
                j++;
            }
        }
        if(i != m){
            for(int count = i; count < m; count++){
                result.push_back(nums1[count]);
                // cout << nums1[count] << endl;
            }
        }
        if(j != n){
            for(int count = j; count < n; count++){
                result.push_back(nums2[count]);
            }
        }

        nums1 = result;
    }
};