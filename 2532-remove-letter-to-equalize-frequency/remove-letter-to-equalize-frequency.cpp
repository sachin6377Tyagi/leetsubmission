class Solution {
public:
    bool equalFrequency(string word) {
        unordered_set<int>st;
        for(auto c:word)st.insert(c);
        unordered_map<int,int>cnt;
        for(auto c:word)cnt[c]++;
        for(auto it:st){
            set<char>temp;
            cnt[it]--;
            for(auto it:cnt){
                if(it.second)temp.insert(it.second);
            }
            if(temp.size()==1)return true;
            cnt[it]++;
        }
        return false;
    }
};