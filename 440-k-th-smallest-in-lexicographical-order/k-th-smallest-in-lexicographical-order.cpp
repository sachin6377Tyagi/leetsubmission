class Solution {
public:
   int Count(long long curr,long long next,int n){
    int cnt=0;
    while(curr<=n){
        cnt+=(next-curr);
        curr=curr*10;
        next=next*10;
        next=min(next,(long long)n+1);
    }
    return cnt;
   }
    int findKthNumber(int n, int k) {
        long long curr=1;
        k--;
        while(k>0){
            int cnt=Count(curr,curr+1,n);
            if(cnt<=k){
                curr++;
                k-=cnt;
            }
            else{
                curr=curr*10;
                k--;
            }
        }
        return curr;
    }
};