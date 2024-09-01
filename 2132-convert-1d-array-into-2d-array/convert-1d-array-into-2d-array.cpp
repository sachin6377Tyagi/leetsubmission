class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& arr, int m, int n) {
        int len=arr.size();
        if((m*n)!=len)return {};
        vector<vector<int>>ans(m,vector<int>(n));
        int k=0;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j)ans[i][j]=arr[k++];
        }
        return ans;
    }
};