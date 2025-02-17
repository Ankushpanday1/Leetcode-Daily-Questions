class Solution {
    
    void backtrack(string tiles, int level, int &count)
    {
        count++;
        for(int i=level; i<tiles.length(); i++){
            
            if(i!=level && tiles[i]==tiles[level])
                continue;   // to skip same characters
            swap(tiles[i], tiles[level]);
            backtrack(tiles, level+1, count);
        }
    }
    
public:
    int numTilePossibilities(string tiles) {
        
        int count=-1;
        sort(tiles.begin(), tiles.end()); 
        
        backtrack(tiles, 0, count); //level = susbstring length
        
        return count;
    }
};