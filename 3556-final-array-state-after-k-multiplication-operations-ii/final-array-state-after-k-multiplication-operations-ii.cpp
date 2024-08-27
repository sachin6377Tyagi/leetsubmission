class Solution {
public:
   long long N=1e9+7;
    vector<int> getFinalState(vector<int>& nums, int k, int mul) {
        if(mul==1)return nums;
         priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>>pq;
       int n=nums.size();
       long long maxi=0;
       for(int i=0;i<n;++i){
        pq.push({nums[i],i});
        if(nums[i]>maxi){
            maxi=nums[i];
        }
       }
       while(k>0){
        if(pq.top().first*mul>maxi)break;
        auto p=pq.top();
        pq.pop();
        long long num=p.first;
        long long i=p.second;
        num=(num*mul)%N;
        pq.push({num,i});
        k--;
       }

        long long q=k/n;
       // cout<<q<<endl;
        vector<pair<long long,long long>>vec(n);
        long long pow=1;
        long long a=mul,b=q;
        bool flag=0;
        while(b){
            if(b&1)pow=(pow*a)%N;
            a=(a*a)%N;
            b=b/2;
        }
       int i=0;
        while(pq.size()){
            auto it=pq.top();
            pq.pop();
            long long num=((it.first)%N*pow)%N;
            if(k-(q*n)>i)num=(num*mul)%N;
            vec[i]={num,it.second};
            i++;
        }
        for(int i=0;i<n;++i)pq.push(vec[i]);
       vector<int>ans(n);
       while(pq.size()){
        auto p=pq.top();
        pq.pop();
        ans[p.second]=p.first;
       }
       return ans;
    }
};