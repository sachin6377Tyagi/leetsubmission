class Solution {
public:
  long long  cntNum(long long x,vector<int>& coins){
    int n=coins.size();
    long long ans=0;
    for(int i=1;i<(1<<n);++i){
        long long lcm=0,cnt=0;
        for(int j=0;j<n;++j){
            if(i&(1<<j)){
                cnt++;
                if(lcm==0)lcm=coins[j];
                else lcm=(lcm*coins[j])/__gcd(lcm,(long long)coins[j]);
            }
        }
        if(cnt%2==0)ans-=(x/lcm);
        else ans+=(x/lcm);
    }
    return ans;
  }
    long long findKthSmallest(vector<int>& coins, int k) {
        long long lo=1,hi=1e18;
        long long ans;
        while(lo<=hi){
            long long mid=(lo+hi)/2;
            if(cntNum(mid,coins)>=k){
                ans=min(ans,mid);
                hi=mid-1;
            }
            else lo=mid+1;
        }
        return ans;
    }
};