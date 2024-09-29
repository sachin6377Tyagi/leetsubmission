class Solution {
public:
    char kthCharacter(long long k, vector<int>& op) {
        int n=op.size();
        char ans='a';
        long long x=k-1;
        int i=0;
        while(x && i<n){
            int rem=x%2;
            if(rem&op[i]){
                if(ans=='z')ans='a';
                else ans=ans+1;
            }
            x=x/2;
            i++;
        }
        return ans;
    }
};