class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
             int n = digits.size();
        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] == 9) {
                // If the current digit is 9, set it to 0 and continue to the next digit
                digits[i] = 0;
            } else {
                // If the current digit is not 9, increment it and return the result
                digits[i]++;
                return digits;
            }
        }
        
        // If we reached here, it means all digits were 9, so we need to add a new digit 1 at the beginning
        digits.insert(digits.begin(), 1);
        return digits;
    }
};