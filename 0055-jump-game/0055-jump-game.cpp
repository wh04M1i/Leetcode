class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int farthest = 0; 
        
        for (int i = 0; i < n; i++) {
            if (i > farthest) {
              
                return false;
            }
            farthest = max(farthest, i + nums[i]); 
            if (farthest >= n - 1) {
              
                return true;
            }
        }
        
        return farthest >= n - 1;
    }
};
