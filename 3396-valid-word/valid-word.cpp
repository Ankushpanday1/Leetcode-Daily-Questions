#pragma GCC optimize("03", "unroll-loops")
class Solution {
public:
    bool isValid(string word) {
       unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        unordered_set<char> consonants;
        for (char c = 'A'; c <= 'Z'; ++c) {
            if (vowels.find(c) == vowels.end()) {
                consonants.insert(c);
                consonants.insert(c + 32);
            }
        }
        bool hasVowel = false;
        bool hasConsonant = false;
        for (char c : word) {
       
            if (!isalnum(c)) {
                return false;
            }
    
            if (vowels.find(c) != vowels.end()) {
                hasVowel = true;
            }
       
            if (consonants.find(c) != consonants.end()) {
                hasConsonant = true;
            }
        }
        return word.length() >= 3 && hasVowel && hasConsonant;
    }
};
auto init = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();