class Solution {
public:
    bool doesAliceWin(string s) {
        for (char c : s) {
            if (isVowel(c)) {
                return true;
            }
        }
        return false;
    }
    
private:
    bool isVowel(char c) 
    {
        return c == 'a' || c == 'i' || c == 'e' || c == 'o' || c == 'u';
    }
};