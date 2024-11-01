class Solution {
public:
  long long dp[105][105];
   long long solve(int i,int j,vector<int>& robot, vector<vector<int>>& factory){
    if(i==robot.size())return 0;
    if(j==factory.size())return 1e15;
    if(dp[i][j]!=-1)return dp[i][j];
    long long ans=1e15;
    ans=min(ans,solve(i,j+1,robot,factory));
    long long sum=0;
    for(int k=i;k<robot.size() && k<i+factory[j][1];++k){
        sum+=abs(robot[k]-factory[j][0]);
        ans=min(ans,sum+solve(k+1,j+1,robot,factory));
    }
    return dp[i][j]= ans;
   }
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(),robot.end());
        sort(factory.begin(),factory.end());
        memset(dp,-1,sizeof(dp));
        return solve(0,0,robot,factory);
    }
};