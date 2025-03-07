//Panday Jii Rocks 
class Solution {
public:
    map<vector<int>, int> mp; // Memoization map to store computed results for each set of needs

    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int n = price.size(); // Number of different items
        int m = special.size(); // Number of special offers

        // Check if the current set of needs has already been computed
        if (mp.count(needs)) {
            return mp[needs]; // Return the stored result if available
        }

        int ans = 0;
        // Calculate the cost without using any special offers
        for (int i = 0; i < needs.size(); ++i) {
            ans += price[i] * needs[i]; // Calculate cost for each item at regular price
        }

        // Iterate through each special offer
        for (int i = 0; i < m; ++i) {
            bool flag = true;

            // Check if the current special offer can be applied
            for (int j = 0; j < n; ++j) {
                if (needs[j] < special[i][j]) {
                    flag = false;
                    break;
                }
            }

            if (flag) {
                // Apply the special offer
                for (int j = 0; j < n; ++j) {
                    needs[j] -= special[i][j]; // Update needs after applying the offer
                }

                // Recursive call to compute the cost after applying the special offer
                int offerCost = special[i].back(); // Cost of the special offer
                int costAfterOffer = offerCost + shoppingOffers(price, special, needs);
                ans = min(ans, costAfterOffer); // Update minimum cost found

                // Restore needs after evaluating the offer
                for (int j = 0; j < n; ++j) {
                    needs[j] += special[i][j]; // Restore needs back to original state
                }
            }
        }

        // Memoize the result for the current set of needs
        mp[needs] = ans;

        return ans; // Return the minimum cost to satisfy the needs
    }
};


