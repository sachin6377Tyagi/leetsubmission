class Solution {
public:
   int cntNum(int m,int n,int mid){
    int ans=0;
    for(int i=1;i<=m;++i){
        ans+=min(n,mid/i);
    }
    return ans;
   }
    int findKthNumber(int m, int n, int k) {
        int lo=1,hi=m*n;
        int ans=m*n;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            if(cntNum(m,n,mid)>=k){
                ans=min(ans,mid);
                hi=mid-1;
            }
            else lo=mid+1;
        }
        return ans;
    }
};