class Solution {
public:
    int maximumScore(int a, int b, int c) {
        int total = a + b + c;
        int mx = max({a, b, c});

        return min(total / 2, total - mx);
    }
};