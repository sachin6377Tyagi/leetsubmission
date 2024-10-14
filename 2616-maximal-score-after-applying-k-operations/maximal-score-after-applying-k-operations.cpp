class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<long long>pq;
        for(int i=0;i<n;++i)pq.push(nums[i]);
        long long ans=0;
        while(k--){
            ans+=pq.top();
            pq.push(ceil(pq.top()/3.0));
            pq.pop();
        }
        return ans;
    }
};