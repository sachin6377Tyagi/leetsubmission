class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int,int>mp;
        for(int i=0;i<arr.size();++i){
            int x=arr[i]%k;
            if(x<0)x=(k+x)%k;
            int y=(k-x)%k;
            if(mp[y]>0)mp[y]--;
            else mp[x]++;
            //cout<<x<<" "<<y<<endl;
        }
        bool flag=1;
        for(int i=0;i<k;++i){
            if(mp[i])flag=0;
        }
        return flag;
    }
};