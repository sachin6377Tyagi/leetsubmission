class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n=s.size();
        map<char,int>mp;
        map<char,bool>vis;
        for(int i=0;i<n;++i){
            mp[s[i]]++;
        }
        stack<pair<char,int>>st;
        for(int i=0;i<n;++i){
            mp[s[i]]--;
            while(!st.empty() && st.top().first>s[i] && mp[st.top().first]>0 && !vis[s[i]]){
                vis[st.top().first]=0;
                st.pop();
            }
            if(!vis[s[i]]){
                st.push({s[i],i});
                vis[s[i]]=1;
            }
        }
        string ans="";
        while(st.size()){
            ans+=st.top().first;
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};