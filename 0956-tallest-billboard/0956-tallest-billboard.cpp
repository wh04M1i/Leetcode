class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        // Map to store the maximum height difference for each state (diff)
        std::unordered_map<int, int> dp;
        dp[0] = 0;

        // Iterate through each rod
        for (int rod : rods) {
            // Create a temporary copy of the dp map to avoid updating the values while iterating
            std::unordered_map<int, int> temp_dp(dp);
            
            // Update the maximum height difference for each state
            for (const auto& entry : dp) {
                int diff = entry.first;
                int height = entry.second;

                // Add the rod to the shorter support
                temp_dp[diff + rod] = std::max(temp_dp[diff + rod], height + rod);
                
                // Add the rod to the taller support
                temp_dp[diff - rod] = std::max(temp_dp[diff - rod], height);
                
                // Discard the rod
                temp_dp[diff] = std::max(temp_dp[diff], height);
            }
            
            // Update the dp map with the temporary values
            dp = temp_dp;
        }
        
        // Return the maximum height difference for the state diff = 0
        return dp[0];
    }
};