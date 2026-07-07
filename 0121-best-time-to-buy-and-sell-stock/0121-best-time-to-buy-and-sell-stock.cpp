class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0];
        int profit = 0;
        
        for(int i = 1; i < prices.size(); i++){
            buy = min(buy, prices[i]);
            profit = max(prices[i] - buy, profit);
        }

        if(profit <= 0){
            return 0;
        }
        return profit;


    }
};