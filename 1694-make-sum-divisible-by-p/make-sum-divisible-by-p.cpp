class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int  n=nums.size();
        long long sum=0,temp=0;
        for(int i=0;i<n;++i)sum+=nums[i];
        int rem=sum%p;
        //cout<<sum<<" "<<rem<<endl;
        if(rem==0)return 0;
        map<int,int>mp;
        mp[0]=-1;
        int ans=n;
        for(int i=0;i<n;++i){
            temp+=nums[i];
            int r=temp%p;
            int x=(r-rem+p)%p;
            if(mp.find(x)!=mp.end())ans=min(ans,i-mp[(r-rem+p)%p]);
            mp[r]=i;
            //cout<<temp<<" "<<r<<" "<<x<<endl;
        }
        if(ans==n)return -1;
        return ans;
    }
};