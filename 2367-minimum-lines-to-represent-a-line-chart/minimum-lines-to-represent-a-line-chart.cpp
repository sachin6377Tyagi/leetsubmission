class Solution {
public:
    int minimumLines(vector<vector<int>>& arr) {
        int n=arr.size();
        if(n==1)return 0;
        int flag;
        sort(arr.begin(),arr.end());
        long long y1=arr[1][1]-arr[0][1],x1=arr[1][0]-arr[0][0];
        int ans=1;
        //for(int i=0;i<n;++i)cout<<arr[i][0]<<" "<<arr[i][1]<<endl;
        for(int i=2;i<n;++i){
           long long y2=arr[i][1]-arr[i-1][1],x2=arr[i][0]-arr[i-1][0];
            if((y1*x2)!=(y2*x1))ans++;
            y1=y2,x1=x2;
        }
        return ans;
    }
};