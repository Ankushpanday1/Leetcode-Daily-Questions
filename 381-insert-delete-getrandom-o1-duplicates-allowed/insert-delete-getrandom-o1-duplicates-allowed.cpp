class RandomizedCollection {
public:
    RandomizedCollection() {
    }
    unordered_map<int, vector<int>> mp;
    vector<long long> v;
	long long temp = (long long)pow(2, 31);
    
    bool insert(int val) {
        auto it = mp.find(val);
        v.push_back((long long)val);
        if(it == mp.end() || it->second.size() == 0){
            
            mp[val].push_back(v.size()-1);
            return true;
        }
        else{
            mp[val].push_back(v.size()-1);
            return false;
        }
    }
    
    bool remove(int val) {
        auto it = mp.find(val);
        if(it == mp.end() || it->second.size() == 0){
            return false;
        }
        else{
            v[mp[val][mp[val].size()-1]] = temp;
            mp[val].pop_back();
            return true;
        }
    }
    
    int getRandom() { 
        long long random = v[rand()%v.size()];
        while(random == temp){
            random = v[rand()%v.size()];
        }
        return random;
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
 