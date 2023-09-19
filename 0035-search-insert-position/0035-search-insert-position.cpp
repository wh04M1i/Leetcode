class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // int i=0;
        // if(nums[nums.size()-1]<target)
        // {
        //     return nums.size();
        // }
        // while(nums[i]<target){i++;}
        // return i;
        
        int s = 0;
        int e = nums.size() - 1; 

        while (s <= e) {
            int m = s + (e - s) / 2;

            if (nums[m] == target) {
                return m; 
            } else if (nums[m] < target) {
                s = m + 1;
            } else {
                e = m - 1; 
            }
        }

        return s;
        
    }
};