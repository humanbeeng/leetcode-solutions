class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int max_profit = 0;
        
        int curr_day = 0;
        
        int n_days = prices.size();
        
        int lowest_so_far = INT_MAX;
        while(curr_day < n_days) {
            
            if(prices[curr_day] < lowest_so_far) {
                lowest_so_far = prices[curr_day];
            }
            
            int todays_profit = prices[curr_day] - lowest_so_far;
            
            max_profit = max(max_profit, todays_profit);
            
            curr_day++;
        }
        
        return max_profit;
    }
};