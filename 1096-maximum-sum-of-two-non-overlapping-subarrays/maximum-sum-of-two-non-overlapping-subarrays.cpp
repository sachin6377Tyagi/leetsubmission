class Solution {
public:
   int solve(vector<int>&pre,int a,int b,int n){
    int ans=0;
    int i=a+b;
    for(;i<=n;++i){
        int x=pre[i]-pre[i-a];
        for(int j=0;j+b<=i-a;++j){
            ans=max(ans,x+pre[j+b]-pre[j]);
        }
    }
    return ans;
   }
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int n=nums.size();
        vector<int>pre(n+1,0);
        for(int i=0;i<n;++i)pre[i+1]=pre[i]+nums[i];
        int ans=solve(pre,firstLen,secondLen,n);
        ans=max(ans,solve(pre,secondLen,firstLen,n));
        return ans;
    }
};