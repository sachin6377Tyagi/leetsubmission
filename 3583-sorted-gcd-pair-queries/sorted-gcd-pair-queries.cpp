class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int maxi=nums[n-1];
        vector<int>vec(maxi+1,0);
        for(int i=0;i<n;++i){
            for(int j=1;j<=sqrt(nums[i]);++j){
                if(nums[i]%j==0){
                    int k=nums[i]/j;
                    vec[j]++;
                    if(k!=j)vec[k]++;
                }
            }
        }
        vector<int>ans;
       // for(int i=1;i<=maxi;++i)cout<<vec[i]<<" ";
        vector<long long >sum(maxi+1,0);
        for(int i=maxi;i>0;i--){
            long long s=(vec[i]*1ll*(vec[i]-1))/2;
            for(int j=2*i;j<=maxi;j+=i)s-=sum[j];
            sum[i]=s;
            //cout<<s<<endl;
        }
        int m=sum.size();
        vector<long long>pre(maxi+1,0);
        for(int i=1;i<=maxi;++i)pre[i]=pre[i-1]+sum[i];
        for(auto x:queries){
            int num=lower_bound(pre.begin(),pre.end(),x+1)-pre.begin();
            ans.push_back(num);
        }
        return ans;
    }
};