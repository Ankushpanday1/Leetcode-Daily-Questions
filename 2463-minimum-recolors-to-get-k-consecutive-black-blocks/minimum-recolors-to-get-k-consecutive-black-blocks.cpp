//Solution by Ankush Panday

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int White = 0, ans = INT_MAX;
        int n = blocks.size();
        int i = 0, j = 0;

      // This loop for 1st window
        for (j = 0; j < k; j++) {
            if (blocks[j] == 'W') 
                White++;
        }
        ans = min(ans, White);
       // This loop for rest 'n-k' windows
        while (j < n) {
            if (blocks[i] == 'W') 
                White--; // remove first element from window
            if (blocks[j] == 'W') 
                White++; // add new element in window
            
            ans = min(ans, White);
            i++, j++;
        }

        return ans;
    }
};