class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, -1);
        stack<int> stack;

        for (int i = 0; i < 2 * n; i++) {
            while (!stack.empty() && nums[i % n] > nums[stack.top()]) {
                result[stack.top()] = nums[i % n];
                stack.pop();
            }

            if (i < n) {
                stack.push(i);
            }
        }

        return result;
    }
};
