class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle overflow
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        long long dvd = llabs((long long)dividend);
        long long dvs = llabs((long long)divisor);

        long long ans = 0;

        while (dvd >= dvs) {
            int shift = 0;

            while (dvd >= (dvs << (shift + 1))) {
                shift++;
            }

            ans += (1LL << shift);
            dvd -= (dvs << shift);
        }

        // Apply sign
        if ((dividend < 0) ^ (divisor < 0))
            ans = -ans;

        return (int)ans;
    }
};