class Solution {
public:
    const int N=1e9+7;
    //map<int,map<int,vector<vector<int>>>>dp;
    long long dp[5001][334][3];
    int solve(int i,int up,int j,int n){
        if(i==n )return 1;
        //if(dp.find())return dp[i][j][up][left];
        if(dp[i][up][j]!=-1)return dp[i][up][j];

        long long ans=0;
        vector<int>vec(4,0);
        int num,div;
        if(j==0){
            vec[up%10]=1;
            num=up%10;
            div=1;
        }
        else if(j==1){
            vec[(up%10)]=1;
            vec[((up/10)%10)]=1;
            num=((up/10)%10);
            div=10;
        }
        else{
            vec[((up/10)%10)]=1;
            vec[((up/100)%10)]=1;
            num=(up/100)%10;
            div=100;
        }
        for(int k=1;k<=3;++k){
            if(vec[k]==1)continue;
            up-=(num*div);
            up+=(k*div);
            if(j==2)ans=(ans+solve(i+1,up,0,n))%N;
            else ans=(ans+solve(i,up,j+1,n))%N;
            up-=(k*div);
            up+=(num*div);
        }
        return dp[i][up][j]=  ans;
    }
    int numOfWays(int n) {
        //vector<vector<int>>grid(n,vector<int>(3,-1));
        memset(dp,-1,sizeof(dp));
        // cout<<(10<<0)<<" "<<(10<<1)<<" "<<(10<<2)<<" "<<(3<<3)<<" "<<(3<<4)<<endl;
        return solve(0,0,0,n);
    }
};