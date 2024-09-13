class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n=arr.size();
        vector<int>pre(n);
        pre[0]=arr[0];
        for(int i=1;i<n;++i)pre[i]=(pre[i-1]^arr[i]);
        vector<int>res;
        for(auto q:queries){
            int l=q[0],r=q[1];
            int ans=pre[r];
            if(l>0)ans=(ans^pre[l-1]);
            res.push_back(ans);
        }
        return res;
    }
};