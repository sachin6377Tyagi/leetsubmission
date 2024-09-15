class Solution {
public:
   static bool cmp(vector<int>&a,vector<int>&b){
    if(a[0]==b[0])return a[1]>b[1];
    return a[0]<b[0];
   }
   int lis(vector<int>&arr){
    vector<int>vec;
    for(int i=0;i<arr.size();++i){
        auto it=lower_bound(vec.begin(),vec.end(),arr[i])-vec.begin();
        if(it==vec.size())vec.push_back(arr[i]);
        else vec[it]=arr[i];
    }
    return vec.size();
   }
    int maxPathLength(vector<vector<int>>& co, int k) {
        int n=co.size();
        int x=co[k][0],y=co[k][1];
        sort(co.begin(),co.end(),cmp);
        vector<int>left;
        vector<int>right;
        for(auto a:co){
            if(a[0]<x && a[1]<y)left.push_back(a[1]);
            else if(a[0]>x && a[1]>y)right.push_back(a[1]);
        }
        int ans1=lis(left);
        int ans2=lis(right);
        return ans1+ans2+1;
    }
};