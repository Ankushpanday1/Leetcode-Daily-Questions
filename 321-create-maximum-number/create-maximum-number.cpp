class Solution {
    string largestSubsequence(vector<int>& nums, int k){
        string ans = "";
        int n = nums.size();
        for(int i = 0; i < n; i++){
            while( n - i > k - ans.size() && !ans.empty() && ans.back() - '0' < nums[i] )
                ans.pop_back(); 
            if( ans.size() < k )
                ans += to_string(nums[i]);
        }
        return ans;
    }

    string largestMerge(string word1, string word2) {
        string ans = "";
        int i = 0, j = 0, m = word1.length(), n = word2.length();
        while( i < m && j < n ){
            if( word1[i] < word2[j] )
                ans += word2[j++];
            else if( word1[i] > word2[j] )
                ans += word1[i++];
            else{
                string w1 = word1.substr(i), w2 = word2.substr(j);
                if( w1 >= w2 )
                    ans += word1[i++];
                else
                    ans += word2[j++];
            }
        }

        if( i < m )
            ans += word1.substr(i);
        if( j < n  )
            ans += word2.substr(j);

        return ans;
    }

    //NOTE: default max function does lexicogrphical comp. on strings
    //thus custom compare func for integer comparision
    string maxStr(string str1, string str2){
        if( str1.length() >  str2.length() )
            return str1;
        if( str2.length() > str1.length() )
            return str2;
        
        return max(str1, str2);
    }

public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int k1 = 0;
        string ans = "";
        //try out all possible combinations of k1 and k2
        while( k1 <= k ){
            string n1 = largestSubsequence(nums1, k1);
            string n2 = largestSubsequence(nums2, k - k1);

            ans = maxStr(ans, largestMerge(n1, n2));
            k1++;
        }

        //construct the vector from string
        vector<int> res(ans.begin(), ans.end());
        
        //As we create vector from string we get the ASCII values
        //of each character in our vector
        //convert it to integer by subtracting 48 as '0' = 48 in ASCII
        for(int i = 0; i < k; i++)
            res[i] -= 48;
            
        return res;
    }
};