class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int nonZeroIndex = 0;

        // Move all non-zero elements to the left
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                nums[nonZeroIndex++] = nums[i];
            }
        }

        // Fill the remaining positions with zeros
        for (int i = nonZeroIndex; i < n; i++) {
            nums[i] = 0;
        }
    }
};
