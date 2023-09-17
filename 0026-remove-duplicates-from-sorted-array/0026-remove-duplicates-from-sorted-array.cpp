class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
  if (nums.empty()) {
            return 0;
        }
        
        int uniqueIndex = 0; // Index to keep track of the last unique element
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[uniqueIndex]) {
                uniqueIndex++;
                nums[uniqueIndex] = nums[i];
            }
        }
        
        // uniqueIndex + 1 gives the count of unique elements
        return uniqueIndex + 1;}
        
       
        
};