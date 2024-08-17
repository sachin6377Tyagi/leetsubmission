class Solution {
public:
    long long maxPoints(vector<vector<int>>& pts) {
        long long ans=0;
        int n=pts.size(),m=pts[0].size();
        vector<long long>pre(m);
        for(int i=0;i<m;++i)pre[i]=pts[0][i];
        for(int i=1;i<n;++i){
            vector<long long>left(m),right(m);
            left[0]=pre[0];
            for(int j=1;j<m;++j)left[j]=max(pre[j],left[j-1]-1);
            right[m-1]=pre[m-1];
            for(int j=m-2;j>=0;j--)right[j]=max(pre[j],right[j+1]-1);
            vector<long long>curr(m);
            for(int j=0;j<m;++j)curr[j]=max(left[j],right[j])+pts[i][j];
            pre=curr;
        }
        for(int i=0;i<m;++i)ans=max(ans,pre[i]);
        return ans;
    }
};