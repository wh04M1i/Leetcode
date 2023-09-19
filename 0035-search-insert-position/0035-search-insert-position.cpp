class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i=0;
        if(nums[nums.size()-1]<target)
        {
            return nums.size();
        }
        while(nums[i]<target){i++;}
        return i;
    }
};