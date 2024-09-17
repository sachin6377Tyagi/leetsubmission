class Solution {
public:
   void compute(vector<int>&nums,vector<vector<pair<int,int>>>&pre,vector<vector<pair<int,int>>>&suff){
    int n=nums.size();
    pre[0][nums[0]]={1,1};
    for(int i=1;i<n;++i){
        pre[i]=pre[i-1];
        pre[i][nums[i]].first=1;
        pre[i][nums[i]].second=max(pre[i][nums[i]].second,1);

        for(int j=1;j<128;++j){
            if(pre[i-1][j].first==1e9)continue;
            int val=(j|nums[i]);
            pre[i][val].first=min(pre[i][val].first,1+pre[i-1][j].first);
            pre[i][val].second=max(pre[i][val].second,1+pre[i-1][j].second);
        }
    }

    suff[n-1][nums[n-1]]={1,1};
    for(int i=n-2;i>=0;i--){
        suff[i]=suff[i+1];
        suff[i][nums[i]].first=1;
        suff[i][nums[i]].second=max(suff[i][nums[i]].second,1);

        for(int j=1;j<128;++j){
            if(suff[i+1][j].first==1e9)continue;
            int val=(nums[i]|j);
            suff[i][val].first=min(suff[i][val].first,1+suff[i+1][j].first);
            suff[i][val].second=max(suff[i][val].second,1+suff[i+1][j].second);
        }
    }
   }

   bool isPossible(int left,int right,int k,int n,vector<vector<pair<int,int>>>&pre,vector<vector<pair<int,int>>>&suff){
    for(int i=0;i<n-1;++i){
        pair<int,int>l=pre[i][left];
        pair<int,int>r=suff[i+1][right];

        if((l.first<=k && l.second>=k) && (r.first<=k && r.second>=k))return true;
    }
    return false;
   }
    int maxValue(vector<int>& nums, int k) {
        int n=nums.size();
        vector<vector<pair<int,int>>>pre(n+1,vector<pair<int,int>>(128,{1e9,0}));
        vector<vector<pair<int,int>>>suff(n+1,vector<pair<int,int>>(128,{1e9,0}));
        compute(nums,pre,suff);

        int ans=0;

        for(int i=1;i<128;i++){
            for(int j=1;j<128;++j){
                if(isPossible(i,j,k,n,pre,suff)){
                    ans=max(ans,i^j);
                }
            }
        }
        cout<<suff[2][91].first<<" "<<suff[2][91].second<<endl;
        return ans;
    }
};