// 假设把某股票的价格按照时间先后顺序存储在数组中，请问买卖该股票一次可能获得的最大利润是多少？

class Solution {
public:
    // int maxProfit(vector<int>& prices) {
    //     int maxInterest = 0;
    //     int minPrice = INT_MAX;

    //     vector<int> minPrices;
    //     for(int price : prices) {
    //         if(price <= minPrice) {
    //             minPrice = price;
    //             minPrices.push_back(0);
    //         }else {
    //             minPrices.push_back(price - minPrice);
    //         }
    //     }

    //     for(int price : minPrices) {
    //         if(price > maxInterest) maxInterest = price;
    //     }
    //     return maxInterest;
    // }
    int maxProfit(vector<int>& prices) {
        int maxInterest = 0;
        int minPrice = INT_MAX;

        vector<int> minPrices;
        for(int price : prices) {
            if(price <= minPrice) {
                minPrice = price;
            }else {
                maxInterest = (price - minPrice) > maxInterest ? (price - minPrice) : maxInterest;
            }
        }

        for(int price : minPrices) {
            if(price > maxInterest) maxInterest = price;
        }
        return maxInterest;
    }
};