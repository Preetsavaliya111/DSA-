#include <limits.h> // For INT_MAX and INT_MIN

class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        while (x != 0) {
            int digit = x % 10;

            // Check for overflow before multiplying
            if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && digit > 7)) return 0;
            if (ans < INT_MIN / 10 || (ans == INT_MIN / 10 && digit < -8)) return 0;

            ans = ans * 10 + digit;
            x /= 10;
        }
        return ans;
    }
};