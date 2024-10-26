class Solution {
public:
   int N=1e9+7;
    long long solve(int ind,int sum,int flag,string &num,int mini,int maxi,vector<vector<vector<long long>>>&dp){
        if(ind==num.size()){
            if(sum<=maxi && sum>=mini)return 1;
            return 0;
        }
        if(dp[ind][sum][flag]!=-1)return dp[ind][sum][flag];
        long long ans=0;
        int end=flag?9:num[ind]-'0';
        for(int i=0;i<=end;++i){
            int x=flag?1:i!=end;
            ans=(ans+solve(ind+1,sum+i,x,num,mini,maxi,dp))%N;
        }
        return dp[ind][sum][flag]= ans;
    }
    int count(string num1, string num2, int min_sum, int max_sum) {
        vector<vector<vector<long long>>>dp1(23,vector<vector<long long>>(405,vector<long long>(2,-1)));
        vector<vector<vector<long long>>>dp2(23,vector<vector<long long>>(405,vector<long long>(2,-1)));
        long long ans1=solve(0,0,0,num1,min_sum,max_sum,dp1)%N;
        long long ans2=solve(0,0,0,num2,min_sum,max_sum,dp2)%N;
        int flag=0,sum=0;
        for(int i=0;i<num1.size();++i)sum+=num1[i]-'0';
        if(sum>=min_sum && sum<=max_sum)flag=1;
        //cout<<ans2<<" "<<ans1<<endl;
        return ((ans2-ans1+flag)%N +N)%N;
    }
};