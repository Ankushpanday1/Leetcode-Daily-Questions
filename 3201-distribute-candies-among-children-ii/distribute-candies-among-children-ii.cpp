class Solution {
public:
    long long distributeCandies(int n, int limit) {
        return ((n <= limit) * 1LL * (n + 1) * (n + 2) + (limit < n && n <= 3 * limit) * ((min(n - limit - 1, limit) -  max(n - 2 * limit, 0) + 1) * (-2LL * n + 4 * limit + max(n - 2 * limit, 0) + min(n - limit - 1, limit) + 2) + (n - limit <= limit) * (2LL * limit - n + 1) * (n + 2))) / 2;
    }
};