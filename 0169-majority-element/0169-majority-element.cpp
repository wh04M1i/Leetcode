class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int count = 0;
        int i=0;
        while(count<nums.size()/2)
        {
            if(nums[i]==nums[i+1])
            {
                count++;
            }
            i++;
        
        }
        return nums[i];
    }
};