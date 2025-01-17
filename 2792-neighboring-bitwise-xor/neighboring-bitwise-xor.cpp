class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int lastD = derived[derived.size() - 1];
        derived.pop_back();
        int pe = 0;
        for (auto el : derived) {
            if (el!=0) {
                if (pe)
                    pe = 0;
                else
                    pe = 1;
            }
        }
        if (lastD == 1 && pe != 0)
            return true;
        if (lastD == 0 && pe == 0)
            return true;
        pe = 1;
        for (auto el : derived) {
            if (el!=0) {
                if (pe)
                    pe = 0;
                else
                    pe = 1;
            }
        }
        if (lastD == 1 && pe != 1)
            return true;
        if (lastD == 0 && pe == 1)
            return true;
        return false;
    }
};