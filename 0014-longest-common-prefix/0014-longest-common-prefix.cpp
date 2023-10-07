#include <vector>
#include <string>

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // Check for empty input
        if (strs.empty()) {
            return "";
        }
        
        // Find the shortest string in the vector
        string shortest = strs[0];
        for (string s : strs) {
            if (s.length() < shortest.length()) {
                shortest = s;
            }
        }
        
        // Use binary search to find the longest common prefix
        int low = 0;
        int high = shortest.length() - 1;
        
        while (low <= high) {
            int mid = (low + high) / 2;
            string prefix = shortest.substr(0, mid + 1);
            
            bool isCommonPrefix = true;
            for (string s : strs) {
                if (s.substr(0, mid + 1) != prefix) {
                    isCommonPrefix = false;
                    break;
                }
            }
            
            if (isCommonPrefix) {
                // If it's a common prefix, search the right half
                low = mid + 1;
            } else {
                // If it's not a common prefix, search the left half
                high = mid - 1;
            }
        }
        
        return shortest.substr(0, low);
    }
};
