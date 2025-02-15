class Solution {
    bool canPartitionSubstring(string& input, int k, int index, int currentSum) {
        if (index >= input.length()) {
            return currentSum == k;
        }
    
        int num = 0;
        
        for (int i = index; i < input.length(); i++) {
            num = num * 10 + (input[i] - '0');
            
            if (canPartitionSubstring(input, k, i + 1, currentSum + num)) {
                return true;
            }
        }
    
        return false;
}
public:
    int punishmentNumber(int n) {
        int ans = 0;
        
        for(int i = 1; i <= n; i++) {
            string v = to_string(i*i);
            bool k = canPartitionSubstring(v,i,0,0);
            
            if(k) {
                ans += i*i;
            }
        }
        
        return ans;
    }
};