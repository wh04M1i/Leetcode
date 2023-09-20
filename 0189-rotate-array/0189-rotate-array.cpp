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
        
//  
        
        
            // Handle the case where k is larger than the array size
        k = k % n;
        
        // Create a temporary vector to hold the rotated elements
        std::vector<int> temp(nums.begin() + n - k, nums.end());
        
        // Move the first part of the array to the right
        for (int i = n - k - 1; i >= 0; i--) {
            nums[i + k] = nums[i];
        }
        
        // Copy the rotated elements from the temporary vector back to the original vector
        for (int i = 0; i < k; i++) {
            nums[i] = temp[i];
        }
    }
};