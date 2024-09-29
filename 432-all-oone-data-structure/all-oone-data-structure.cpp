class AllOne {
public:
unordered_map<string,int>mp;
map<int,unordered_set<string>>freq;
    AllOne() {
        
    }
    
    void inc(string key) {
      int cnt=mp[key]++;
      if(cnt>0)freq[cnt].erase(key);
      freq[cnt+1].insert(key);
      if(freq[cnt].empty()) freq.erase(cnt);
    }
    
    void dec(string key) {
        int cnt=mp[key]--;;
        if(cnt>0)freq[cnt].erase(key);
        if(cnt==1)mp.erase(key);
        else freq[cnt-1].insert(key);
        if(freq[cnt].empty()) freq.erase(cnt);
    }
    
    string getMaxKey() {
        if(freq.empty())return "";
        return *(freq.rbegin()->second.begin());
    }
    
    string getMinKey() {
        if(freq.empty())return "";
        return *(freq.begin()->second.begin());
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */