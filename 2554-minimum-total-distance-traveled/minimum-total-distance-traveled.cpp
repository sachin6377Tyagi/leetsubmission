class Solution {
public:
    long long dp[105][105][105];
    long long solve(int i,int j,int lim,vector<int>& robot, vector<vector<int>>& factory){
        if(i==robot.size())return 0;
        if(j==factory.size())return 1e15;
        if(dp[i][j][lim]!=-1)return dp[i][j][lim];
        long long ans=1e15;
        if(j+1<factory.size())ans=min(ans,solve(i,j+1,factory[j+1][1],robot,factory));
       if(lim>0) {
            ans=min(ans,abs(robot[i]-factory[j][0])+solve(i+1,j,lim-1,robot,factory));
            //ans=min(ans,solve(i,j+1,factory[j][1],robot,factory));
        }
        return dp[i][j][lim]= ans;
    }
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, factory[0][1],robot, factory);
    }
};

