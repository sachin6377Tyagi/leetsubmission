class Solution {
public:
   int dp[10][2][2][2];
    int solve(int ind,int flag,int safe,int start,string &s,set<int>&st){
        if(ind==s.size())return safe&start;
        if(dp[ind][flag][safe][start]!=-1)return dp[ind][flag][safe][start];
        int ans=0;
        int end=flag?9:s[ind]-'0';
        for(int i=0;i<=end;++i){
            int x=flag?1:i!=end;
            int y=safe;
            int z=start?1:i!=0;
            if(z)if(st.find(i)==st.end())y=0;
            ans+=solve(ind+1,x,y,z,s,st);
        }
        return dp[ind][flag][safe][start]= ans;
    }
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string s=to_string(n);
        set<int>st;
        for(auto c:digits){
            st.insert(c[0]-'0');
        }
        memset(dp,-1,sizeof(dp));
        //for(auto it:st)cout<<it<<endl;
        return solve(0,0,1,0,s,st);
    }
};