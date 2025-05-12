class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        unordered_set<int> nums; // To store unique 3-digit even numbers

        // Try all combinations of 3 different digits
        for(int i = 0 ; i < digits.size() ; i++) {
            for(int j = 0 ; j < digits.size() ; j++) {
                for(int k = 0 ; k < digits.size() ; k++) {
                    // Skip if any two indices are the same (no digit can be reused)
                    if(i == j || j == k || i == k) continue;

                    // Form a 3-digit number from digits[i], digits[j], digits[k]
                    int temp = digits[i]*100 + digits[j]*10 + digits[k];

                    // Check if number is even and a valid 3-digit number
                    if(temp % 2 == 0 && temp >= 100)
                        nums.insert(temp); // Add to set to avoid duplicates
                }
            }
        }

        // Convert set to vector and sort it
        vector<int> result;
        for(auto it : nums) result.push_back(it);

        sort(result.begin(), result.end()); // Sort in ascending order

        return result;
    }
};