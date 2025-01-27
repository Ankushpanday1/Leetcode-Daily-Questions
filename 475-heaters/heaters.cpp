class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        
        int i, n = houses.size(), m = heaters.size();  
        int ans = INT_MIN, nextHeater, prevHeater, curr;
        
        map<int, int> mp;
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        
        
        for(i=0;i<n;i++)
        {
            curr = houses[i];
            nextHeater = upper_bound(heaters.begin(), heaters.end(), curr) - heaters.begin();
            prevHeater = nextHeater - 1;
            
            if(nextHeater == 0)
                mp[houses[i]] = heaters[nextHeater] - houses[i];
            else if (nextHeater == m)
                mp[houses[i]] = houses[i] - heaters[prevHeater];
            else
                mp[houses[i]] = min(heaters[nextHeater] - houses[i], houses[i] - heaters[prevHeater]);
        }
        for(auto el : mp)
            ans = max(ans, el.second);
        return ans;
    }
};