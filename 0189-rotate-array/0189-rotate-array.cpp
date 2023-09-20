#include <bits/stdc++.h>

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
//        while(k>0)
//         {
//            nums.insert(nums.begin(), nums[n-1]);
//             nums.resize(n);
//            k--;

//         }
        
          k = k % n;
        
        // Reverse the entire array
        reverse(nums.begin(), nums.end());
        
        // Reverse the first k elements
        reverse(nums.begin(), nums.begin() + k);
        
        // Reverse the remaining elements
        reverse(nums.begin() + k, nums.end());
    }
};