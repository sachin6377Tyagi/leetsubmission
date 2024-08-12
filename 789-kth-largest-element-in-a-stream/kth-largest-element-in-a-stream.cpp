class KthLargest {
public:
   priority_queue<int,vector<int>,greater<int>>pq;
   int cnt;
    KthLargest(int k, vector<int>& nums) {
        cnt=k;
        for(int i=0;i<nums.size();++i){
            if(pq.size()<k)pq.push(nums[i]);
            else{
                if(nums[i]>pq.top()){
                    pq.pop();
                    pq.push(nums[i]);
                }
            }
        }
    }
    
    int add(int val) {
       if(pq.size()<cnt){
           pq.push(val);
           if(pq.size()==cnt)return pq.top();
           else return -1;
       }
       else{
           if(val>pq.top()){
               pq.pop();
               pq.push(val);
           }
           return pq.top();
       }
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */