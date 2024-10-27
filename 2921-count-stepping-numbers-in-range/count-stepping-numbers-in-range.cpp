class Solution {
public:
   int N=1e9+7;
   int dp[101][10][2][2];
   int solve(int ind,int last,int flag,int start,string &s){
    if(ind==s.size())return 1;
    if(dp[ind][last][flag][start]!=-1)return dp[ind][last][flag][start];
    long long ans=0;
    int end=flag?9:s[ind]-'0';
    for(int i=0;i<=end;++i){
        if(start && abs(last-i)!=1)continue;
        int x=flag?1:i!=end;
        int y=start?1:i!=0;
        ans=(ans+solve(ind+1,i,x,y,s))%N;
    }
    return dp[ind][last][flag][start]= ans;
   }
    int countSteppingNumbers(string low, string high) {
        //vector<vector<vector<vector<int>>>>dp1(101,vector<vector<vector<int>>>(11,vector<vector<int>>(2,vector<int>(2,-1))));
        //vector<vector<vector<vector<int>>>>dp2(101,vector<vector<vector<int>>>(11,vector<vector<int>>(2,vector<int>(2,-1))));
        memset(dp,-1,sizeof(dp));
        int ans1=solve(0,0,0,0,low);
         memset(dp,-1,sizeof(dp));
        int ans2=solve(0,0,0,0,high);
        bool flag=1;
        for(int i=1;i<low.size();++i){
            if(abs(low[i]-low[i-1])!=1)flag=0;
        }
        return ((ans2-ans1+flag)%N +N)%N;
    }
};