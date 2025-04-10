class Solution {
public:
    // Recursive function to calculate the maximum points
    long long solve(long long idx, int n, vector<vector<int>>& questions, vector<long long>& dp) {
        // Base Case: If index exceeds or reaches the last question, return 0 (No more questions left)
        if (idx >= n) {
            return 0;
        }

        // If the answer for this index is already calculated, return it (Memoization step)
        if (dp[idx] != -1) {
            return dp[idx];
        }

        // **Choice 1: Take the current question**
        // - We add the points of the current question
        // - Move to the next question index: `idx + questions[idx][1] + 1` (Skipping cooldown questions)
        long long take = solve(idx + questions[idx][1] + 1, n, questions, dp) + questions[idx][0];

        // **Choice 2: Skip the current question**
        // - Simply move to the next question (`idx + 1`)
        long long not_take = solve(idx + 1, n, questions, dp);

        // Store the maximum result in dp array and return it
        return dp[idx] = max(take, not_take);
    }

    // Main function to initialize and call recursion
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size(); // Get total number of questions
        vector<long long> dp(n + 1, -1); // DP array initialized with -1 (to indicate uncomputed states)

        return solve(0, n, questions, dp); // Start solving from the first question
    }
};