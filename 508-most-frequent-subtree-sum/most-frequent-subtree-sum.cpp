class Solution {
public:
    unordered_map<int, int> mp;
    int solve(TreeNode* root){
          if(!root){
              return 0;
          }
        int left = solve(root->left);
        int right = solve(root->right);
        int sum = left + right + root->val;
        mp[sum]++;
        return sum;
    }
    
    vector<int> findFrequentTreeSum(TreeNode* root) {
        solve(root);
        vector<int> ans;
        int max = INT_MIN;
        for(auto it=mp.begin(); it != mp.end(); it++){
            if(it->second > max){
                max = it->second;
                if(ans.size() > 0){
                    ans.clear();
                }
                ans.push_back(it->first);
            }
            else if(it->second == max){
                ans.push_back(it->first);
            }
        }
        return ans;
    }
};