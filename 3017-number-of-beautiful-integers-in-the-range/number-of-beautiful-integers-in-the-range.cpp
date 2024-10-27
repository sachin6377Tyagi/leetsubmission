class Solution {
public:
   int dp[11][2][21][50][2];
   int solve(int ind,int flag,int par,int rem,int st,int k,string &s){
    if(ind==s.size()){
        if(par==10 && rem==0)return 1;
        return 0;
    }
    if(dp[ind][flag][par][rem][st]!=-1)return dp[ind][flag][par][rem][st];
    int ans=0;
    int end=flag?9:s[ind]-'0';
    for(int i=0;i<=end;++i){
        int x=flag?1:i!=end;
        int z=st?1:i!=0;
        int y=0;
        if(z){
            y=i%2==0?-1:1;
        }
        ans=ans+solve(ind+1,x,par+y,(10*rem+i)%k,z,k,s);
    }
    return dp[ind][flag][par][rem][st]= ans;
   }
    int numberOfBeautifulIntegers(int low, int high, int k) {
        string s1=to_string(low);
        string s2=to_string(high);
        memset(dp,-1,sizeof(dp));
        int ans1=solve(0,0,10,0,0,k,s1);
         memset(dp,-1,sizeof(dp));
        int ans2=solve(0,0,10,0,0,k,s2);
        bool flag=0;
        if(low%k==0){
            int cnt=0;
            for(int i=0;i<s1.size();++i){
                if(s1[i]%2==0)cnt++;
                else cnt--;
            }
            if(cnt==0)flag=1;
        }
        cout<<ans2<<" "<<ans1<<endl;
        return ans2-ans1+flag;
    }
};