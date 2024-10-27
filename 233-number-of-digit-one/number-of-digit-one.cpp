class Solution {
public:
   int dp[10][2][20];
   int solve(int ind,int flag,int cnt,string &s){
    if(ind==s.size())return cnt;
    if(dp[ind][flag][cnt]!=-1)return dp[ind][flag][cnt];
    int ans=0;
    int end=flag?9:s[ind]-'0';
    for(int i=0;i<=end;++i){
        int x=i==1?1:0;
        int y=flag?1:i!=end;
        ans+=(solve(ind+1,y,cnt+x,s));
    }
    return dp[ind][flag][cnt]= ans;
   }
    int countDigitOne(int n) {
        string s=to_string(n);
        memset(dp,-1,sizeof(dp));
        return solve(0,0,0,s);
    }
};