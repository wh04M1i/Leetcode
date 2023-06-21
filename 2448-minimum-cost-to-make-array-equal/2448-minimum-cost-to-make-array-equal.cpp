#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        auto calculateCost = [&](long long l) {
            long long totalCost = 0;
            for (int i = 0; i < nums.size(); i++) {
                totalCost += abs(l - nums[i]) * static_cast<long long>(cost[i]);
            }
            return totalCost;
        };

        int left = *min_element(nums.begin(), nums.end());
        int right = *max_element(nums.begin(), nums.end()) + 1;
        int mid = (left + right) / 2;

        while (left < right) {
            if (calculateCost(mid) < calculateCost(mid + 1)) {
                right = mid;
            } else {
                left = mid + 1;
            }
            mid = (left + right) / 2;
        }

        return calculateCost(left);
    }
};
