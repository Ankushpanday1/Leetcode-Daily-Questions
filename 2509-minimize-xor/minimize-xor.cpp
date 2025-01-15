#include <immintrin.h>

class Solution {
public:
    static int minimizeXor(const uint num1, const uint num2) noexcept __attribute__((hot, __target__("bmi2"))) {
        const int p1 = popcount(num1), p2 = popcount(num2);
        return _pdep_u32(-1 << max(p1 - p2, 0), num1) + _pdep_u32((1 << max(p2 - p1, 0)) - 1, ~num1);
    }
};