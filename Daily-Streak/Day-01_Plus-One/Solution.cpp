class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        // Traverse from the last digit
        for (int i = n - 1; i >= 0; i--) {
            // Add one to the current digit
            digits[i]++;

            // If digit becomes less than 10, no carry needed
            if (digits[i] < 10) {
                return digits;
            }

            // Otherwise, set digit to 0 and continue carry
            digits[i] = 0;
        }

        // If all digits were 9, add 1 at the front
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
