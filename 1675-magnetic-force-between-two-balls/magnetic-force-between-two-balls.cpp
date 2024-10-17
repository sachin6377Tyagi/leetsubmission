class Solution {
public:
   bool isPossible(long long x,vector<int>&arr,int m){
    long long num=arr[0];
    int cnt=1;
    for(int i=1;i<arr.size();++i){
        if(num+x<=arr[i]){
            cnt++;
            num=arr[i];
        }
        if(cnt==m)return true;
    }
    return false;
   }
    int maxDistance(vector<int>& pos, int m) {
        sort(pos.begin(),pos.end());
        int n=pos.size();
        long long lo=1,hi=pos[n-1];
        int ans=0;
        while(lo<=hi){
            long long mid=(lo+hi)/2;
            if(isPossible(mid,pos,m)){
                ans=mid;
                lo=mid+1;
            }
            else hi=mid-1;
        }
        return ans;
    }
};