
class Solution {


    // Declared Height as global variable for class
     int height;

    // Height Function
    int getHeight(TreeNode * root)
    {
        if(!root)  return 0;
        
        return 1 + max(getHeight(root->left) , getHeight(root->right));
    }

    // DFS Method 
    void SolveByDFS(TreeNode * root, vector<vector<string>>  &ans , int r, int c)
    {
        if(!root)
        return ;

        ans[r][c] = to_string(root->val);
        SolveByDFS(root->left, ans, r+1 , c - (pow(2,height-r-1) ) );
        SolveByDFS(root->right, ans, r+1 , c + (pow(2,height-r-1) ) );
        
    }

public:
    vector<vector<string>> printTree(TreeNode* root) {
        
        // Calculate Height using Height Function mentioned above
        height = getHeight(root)-1;

        // Declare rows and column 
        int m = height+1, n  = pow(2, height+1)-1;

        // Declare vector of vector storing answer strings
        vector<vector<string>> ans(m, vector<string> (n , ""));

        //  DFS Method
        // SolveByDFS(root, ans, 0,  (n-1)/2 );


        // BFS Method
        queue<pair<TreeNode* , int> > q;

        q.push({root ,  (n-1)/2 });
        int r = 0;
        
        while(!q.empty())
        {
           int s = q.size();

           for(int i = 0 ; i<s ; i++)
           {
             auto curr = q.front();
             q.pop();
             int c = curr.second;
            TreeNode* curr_node = curr.first;
            
            ans[r][c] = to_string(curr_node -> val);
            
            if(curr_node -> left)
                q.push({curr_node -> left, c - pow(2, height - 1 - r)});
            
            if(curr_node -> right)
                q.push({curr_node -> right, c + pow(2, height - 1 - r)});
           }
           r++;
        }
        return ans;
    }
};