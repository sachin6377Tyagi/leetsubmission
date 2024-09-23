class Solution {
public:
  int dp[51];

  int solve(int ind,set<string>&st,string &s){
    if(ind==s.size())return 0;
    if(dp[ind]!=-1)return dp[ind];

    string curr="";
    int ans=1e9;
    for(int i=ind;i<s.size();++i){
        curr+=s[i];
        int x=0;
        if(st.find(curr)==st.end())x=curr.size();
        ans=min(ans,x+solve(i+1,st,s));
    }
    return dp[ind]= ans;
  }
   
    int minExtraChar(string s, vector<string>& dictionary) {
        set<string>st;
        for(auto it:dictionary)st.insert(it);
        memset(dp,-1,sizeof(dp));
        return solve(0,st,s);
    }
};