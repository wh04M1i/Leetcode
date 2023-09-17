class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i=0;
      
        int s= nums.size();
        while(i<s)
        {
            if(nums[i]==val)
            {
                for(int j=i;j<s-1;j++)
                {
                    nums[j]=nums[j+1];
                }
               // i--;
                s--;
            }
            else
            i++;
        }
      return s;
    }
};