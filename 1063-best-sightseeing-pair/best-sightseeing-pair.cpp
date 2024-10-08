class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n=values.size();
        vector<int>left(n,0),right(n,0);
        for(int i=1;i<n;++i)left[i]=max(left[i-1]-1,values[i-1]-1);
        for(int i=n-2;i>=0;i--)right[i]=max(right[i+1]-1,values[i+1]-1);
        int ans=0;
        for(int i=0;i<n;++i){
            ans=max(ans,left[i]+values[i]);
            ans=max(ans,right[i]+values[i]);
        }
        return ans;
    }
};