class Solution {
public:
    int distinctSubseqII(string s) {
       int n=s.size();
       int N=1e9+7;
       vector<long long>dp(n);
       for(int i=0;i<n;++i){
        int j=i-1;
        while(j>=0){
            dp[i]=(dp[i]+dp[j])%N;
            if(s[j]==s[i])break;
            j--;
        }
        if(j==-1)dp[i]=(dp[i]+1)%N;
       }
       long long ans =0;
       for(int i=0;i<n;++i)ans=(ans+dp[i])%N;
       return ans;
    }
};