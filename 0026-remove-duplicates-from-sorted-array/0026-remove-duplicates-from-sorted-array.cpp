class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        int i=0;
        while(i<size-1){
            if(nums[i]==nums[i+1])
            {
             for(int j=i;j<size-1;j++)   
              nums[j]=nums[j+1];
                size--;
            }
        else
            i++;
        }
        return size;
    }
};