class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
 int n = prices.size();
        if (n <= 1) return 0;  // Handle the case with 0 or 1 day
        
        int minPrice = prices[0];
        int maxProfit = 0;
        
        for (int i = 1; i < n; i++) {
            
            int currentProfit = prices[i] - minPrice;
            
            if (prices[i] < minPrice) {
                minPrice = prices[i];
            }
            
            if (currentProfit > maxProfit) {
                maxProfit = currentProfit;
            }
        }
        
        return maxProfit;
    }
};