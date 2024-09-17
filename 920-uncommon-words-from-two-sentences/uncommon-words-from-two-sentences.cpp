class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        int n=s1.size(),m=s2.size();
        string temp="";
        map<string,int>mp;
        for(int i=0;i<n;++i){
            if(s1[i]==' '){
                mp[temp]++;
                temp="";
            }
            else temp+=s1[i];
        }
        mp[temp]++;
        temp="";
        for(int i=0;i<m;++i){
            if(s2[i]==' '){
                mp[temp]++;
                temp="";
            }
            else temp+=s2[i];
        }
        mp[temp]++;
        vector<string>ans;
        for(auto it:mp){
            if(it.second==1)ans.push_back(it.first);
        }
        return ans;
    }
};