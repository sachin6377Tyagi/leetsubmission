class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n=skill.size();
        sort(skill.begin(),skill.end());
        int temp=skill[0]+skill[n-1];
        bool flag=0;
        for(int i=1;i<n/2;++i){
            int curr=skill[i]+skill[n-i-1];
            if(curr!=temp){
                flag=1;
                break;
            }
        }
        if(flag)return -1;
        long long ans=0;
        for(int i=0;i<n/2;++i){
            ans+=(skill[i]*skill[n-i-1]);
        }
        return ans;
    }
};