class Solution {
public:
    int addDigits(int num) {
        int sum = 10;

        // While sum of digits has more than one digit
        while (sum > 9) {
            
            // Get sum of all digits of num
            sum = 0;
            while (num > 0) {
                sum += num % 10;
                num /= 10;
            }

            num = sum;
        }

        return sum;
    }
};