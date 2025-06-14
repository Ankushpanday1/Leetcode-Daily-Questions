class Solution {
    bool isSelfDividing(int num) {
        int n = num;
        while (n) {
            int digit = n % 10;
            n /= 10;
            if (digit == 0 || num % digit != 0) {
                return false;
            }
        }
        return true;
    }

public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> result;

        for (int i = left; i <= right; i++) {
            if (isSelfDividing(i)) {
                result.push_back(i);
            }
        }

        return result;
    }
};