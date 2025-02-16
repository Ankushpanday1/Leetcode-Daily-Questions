class Solution {
public:
    bool checkRecord(string s) {
        int count = 0;
        for (auto& ch : s) {
            if (ch == 'A') {
                count++;
                if (count >= 2) {
                    return false;
                }
            }
        }
        return s.find("LLL") == string::npos;  // Check if "LLL" is not found
    }
};
