class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = 32767;
        int maxprofit = 0;
        for(int i = 0; i < prices.size(); i++){
            if(prices[i] < minPrice){
                minPrice = prices[i];
            }
            else if(prices[i] - minPrice > maxprofit){
                maxprofit = prices[i] - minPrice;
            }
        }
        return maxprofit;
    }
};