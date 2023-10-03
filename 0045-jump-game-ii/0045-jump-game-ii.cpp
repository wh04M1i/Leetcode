class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        
        if (n <= 1) {
            return 0;  // No jumps needed for an empty array or an array with only one element.
        }
        
        int maxReach = nums[0]; // The farthest index we can reach with the current jump.
        int steps = nums[0];    // The number of steps remaining for the current jump.
        int jumps = 1;          // Number of jumps taken so far.
        
        for (int i = 1; i < n; i++) {
            // If we reach or exceed the end of the array, return the number of jumps.
            if (i == n - 1) {
                return jumps;
            }
            
            // Update the maximum reachable index if we find a better one.
            maxReach = max(maxReach, i + nums[i]);
            
            // Reduce the remaining steps for the current jump.
            steps--;
            
            // If there are no more steps left for the current jump, we need to take a new jump.
            if (steps == 0) {
                jumps++;
                
                // Check if we can't move forward anymore (i.e., maxReach <= i).
                if (maxReach <= i) {
                    return -1; // Can't reach the end of the array.
                }
                
                // Update the remaining steps for the new jump.
                steps = maxReach - i;
            }
        }
        
        return -1; // If we can't reach the end of the array.
    }
};
