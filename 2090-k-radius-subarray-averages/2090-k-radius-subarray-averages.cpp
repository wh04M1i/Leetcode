#include <vector>

class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> avgs(n, -1);

        long long sum = 0;
        int count = 0;

        // Calculate the sum of the first 2k+1 elements
        for (int i = 0; i <= 2 * k && i < n; i++) {
            sum += nums[i];
            count++;
        }

        // Compute the average for the first k centers
        for (int i = k; i < n - k; i++) {
            avgs[i] = sum / count;

            // Subtract the element that falls outside the window
            if (i - k >= 0) {
                sum -= nums[i - k];
                count--;
            }

            // Add the element that enters the window
            if (i + k + 1 < n) {
                sum += nums[i + k + 1];
                count++;
            }
        }

        return avgs;
    }
};
