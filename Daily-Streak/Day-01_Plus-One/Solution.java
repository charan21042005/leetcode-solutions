class Solution {
    public int[] plusOne(int[] digits) {
        int n = digits.length;

        // Traverse from the last digit
        for (int i = n - 1; i >= 0; i--) {
            // Add one to the current digit
            digits[i]++;

            // If no carry is generated, return result
            if (digits[i] < 10) {
                return digits;
            }

            // Carry case
            digits[i] = 0;
        }

        // If all digits were 9, create new array
        int[] result = new int[n + 1];
        result[0] = 1;
        return result;
    }
}
