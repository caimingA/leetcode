class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if(m == 0){
            if(n%2== 0){
                return (nums2[n/2] + nums2[n/2 - 1])/2.0;
            }else{
                return nums2[n/2];
            }
        }
        if(n == 0){
            // cout << m << "/" << n << endl;
            if(m%2== 0){
                return (nums1[m/2] + nums1[m/2 - 1])/2.0;
            }else{
                return nums1[m/2];
            }
        }
        if(n == 1 && m == 1){
            return (nums1[0] + nums2[0]) / 2.0;
        }
        int p1 = 0;
        int p2 = 0;
        int flag = 0;
        vector<int> resultList;
        while(p1 != m && p2 != n){
            if(nums1[p1] < nums2[p2]){
                resultList.push_back(nums1[p1]);
                p1++;
                if(p1 == m)
                    flag = 1;
            }else{
                resultList.push_back(nums2[p2]);
                p2++;
                if(p2 == n)
                    flag = 2;
            }
        }
        if(flag == 1){
            while(p2 != n){
                resultList.push_back(nums2[p2]);
                p2++;
            }
        }
        if(flag == 2){
            while(p1 != m){
                resultList.push_back(nums1[p1]);
                p1++;
            }    
        }
        for(int i = 0; i < resultList.size(); i++){
            cout << resultList[i] << endl;
        }
        if((m+n)%2==0){
            return (resultList[(m+n)/2] + resultList[(m+n)/2 - 1]) / 2.0;
        }else{
            return resultList[(m+n)/2];
        }
    }
};