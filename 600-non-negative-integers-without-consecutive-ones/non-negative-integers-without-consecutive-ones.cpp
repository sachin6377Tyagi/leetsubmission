class Solution {
public:
  int dp[35][2][2];
   int solve(int ind,int flag,int isOne,string &s){
    if(ind==s.size())return 1;
    if(dp[ind][flag][isOne]!=-1)return dp[ind][flag][isOne];
    int ans=0;
    int end=flag?1:s[ind]-'0';
    for(int i=0;i<=end;++i){
        if(isOne && i==1)continue;
        int x=flag?1:i!=end;
        int y=i==1?1:0;
        ans=(ans+solve(ind+1,x,y,s));
    }
    return dp[ind][flag][isOne]= ans;
   }
    int findIntegers(int n) {
        string s="";
        while(n){
            int rem=n%2;
            s+=to_string(rem);
            n=n/2;
        }
        reverse(s.begin(),s.end());
        memset(dp,-1,sizeof(dp));
        return solve(0,0,0,s);
    }
};