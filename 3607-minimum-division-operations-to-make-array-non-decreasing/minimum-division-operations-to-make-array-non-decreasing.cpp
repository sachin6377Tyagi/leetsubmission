class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans=0,n=nums.size();
        bool f=0;
        if(n==1)return 0;
        for(int i=n-2;i>=0;i--){
            if(nums[i]>nums[i+1]){
                int temp=nums[i];
                vector<int>vec;
                bool flag=0;
                for(int j=2;j<=sqrt(nums[i]);++j){
                    if(nums[i]%j==0){
                        vec.push_back(nums[i]/j);
                        vec.push_back(j);
                    }
                }
                sort(vec.begin(),vec.end());
                for(int j=0;j<vec.size();++j){
                    if(nums[i]/vec[j]<=nums[i+1]){
                        temp=nums[i]/vec[j];
                        flag=1;
                        break;
                    }
                }
                ans+=flag;
                nums[i]=temp;
            }
        }
        for(int i=1;i<n;++i){
            if(nums[i]<nums[i-1])f=1;
        }
        if(f)return -1;
        return ans;
    }
};