class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> temp ;
        sort(nums.begin(),nums.end());
        for (int i=0; i<nums.size()-1 ; i++)
        {
                if(nums[i]==nums[i+1])
                    temp.push_back(nums[i]);
            
        }
        return temp;
    }
};