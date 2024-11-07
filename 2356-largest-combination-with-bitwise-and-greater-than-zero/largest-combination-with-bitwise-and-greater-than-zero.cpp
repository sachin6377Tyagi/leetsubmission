class Solution {
public:
    int largestCombination(vector<int>& arr) {
        int n=arr.size();
        int ans=0;
        for(int i=0;i<32;++i){
            int cnt=0;
            for(auto it:arr){
                if((1<<i)&it)cnt++;
            }
            ans=max(ans,cnt);
        }
        return ans;
    }
};