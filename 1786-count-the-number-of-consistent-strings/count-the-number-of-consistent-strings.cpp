class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char>st;
        for(auto a:allowed)st.insert(a);
        int cnt=0;
        for(auto s:words){
            int flag=1;
            for(int i=0;i<s.size();++i){
                if(st.find(s[i])==st.end()){
                    flag=0;
                    break;
                }
            }
            cnt+=flag;
        }
        return cnt;
    }
};