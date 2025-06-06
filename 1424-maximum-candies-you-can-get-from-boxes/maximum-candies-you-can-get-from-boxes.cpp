class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n = candies.size();
        queue<int> q;
        vector<bool> keysFound(n);
        set<int> waitingKeys;
        for(int i: initialBoxes){
            if(status[i])
                q.push(i);
            else
                waitingKeys.insert(i);
        }

        int sum = 0;
        
        while(!q.empty()){
            int kagi = q.front();
            q.pop();
            sum += candies[kagi];

            for(int newKey: keys[kagi]){
                keysFound[newKey] = true;
                if(waitingKeys.count(newKey)){
                    q.push(newKey);
                    waitingKeys.erase(newKey);
                }
            }


            for(int candy: containedBoxes[kagi]){
                if((status[candy] or keysFound[candy])){
                    q.push(candy);
                }
                else if(!status[candy]){
                    waitingKeys.insert(candy);
                }
            }
        }
        return sum;
    }
};