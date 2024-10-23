class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int n=nums.size();
       for(int i=0;i<n;++i){
        if(nums[i]%2==1)nums[i]=2*nums[i];
       } 
       priority_queue<int>pq;
       int mini=1e9;
       for(int i=0;i<n;++i){
        pq.push(nums[i]);
        mini=min(mini,nums[i]);
       }
       int ans=1e9;
       while(pq.top()%2==0){
        int tp=pq.top();
        ans=min(ans,tp-mini);
        pq.pop();
        pq.push(tp/2);
        if(tp/2<mini)mini=tp/2;
       }
       return min(ans,pq.top()-mini);
    }
};