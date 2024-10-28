class Solution {
public:
  unordered_map<int,int>dp;
   int solve(int n){
    if(n<=1)return 1;
    if(dp[n]==0)dp[n]= 1+min((n%2)+solve(n/2),(n%3)+solve(n/3));
    return dp[n];
   }
    int minDays(int n) {
        return solve(n);
    }
};