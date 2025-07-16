class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int allEven = 0, allOdd = 0;
        int altEvenOdd = 0, altOddEven = 0;

        for (int num : nums) {
            if (num % 2 == 0) allEven++;
            else allOdd++;
        }

        int expect = 0;
        for (int num : nums) {
            if (num % 2 == expect) {
                altEvenOdd++;
                expect ^= 1;
            }
        }

        expect = 1;
        for (int num : nums) {
            if (num % 2 == expect) {
                altOddEven++;
                expect ^= 1;
            }
        }

        return max({allEven, allOdd, altEvenOdd, altOddEven});
    }
};