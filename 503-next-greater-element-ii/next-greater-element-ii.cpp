class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& a) {
        int n = a.size();
        vector<int> ans(n, -1);
        stack<int> st;
        
        // Iterate through a twice
        for (int k = 0; k < 2; ++k) {
            for (int i = n - 1; i >= 0; --i) {
                while (!st.empty() && st.top() <= a[i]) {
                    st.pop();
                }
                if (!st.empty()) {
                    ans[i] = st.top();
                }
                st.push(a[i]);
            }
        }
        return ans;
    }
};