class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = INT_MIN;
        
        int buy_price = INT_MAX;
        
        for(int curr_trading_price: prices) {
            
            buy_price = min(buy_price, curr_trading_price);
            
            int curr_profit = curr_trading_price - buy_price;
            
            max_profit = max(max_profit, curr_profit);
            
        }
        
        return (max_profit == INT_MIN) ? -1 : max_profit; 
    }
};