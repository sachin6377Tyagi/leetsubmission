class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int ans=2,n=points.size();
        if(n<=2)return n;
        for(int i=0;i<n;++i){
            for(int j=i+1;j<n;++j){
                long long y1=points[i][1]-points[j][1],x1=points[i][0]-points[j][0];
                int cnt=2;
                for(int k=j+1;k<n;++k){
                    long long y2=points[k][1]-points[j][1],x2=points[k][0]-points[j][0];
                    if(x1*y2==y1*x2)cnt++;
                }
                ans=max(ans,cnt);
            }
        }
        return ans;
    }
};