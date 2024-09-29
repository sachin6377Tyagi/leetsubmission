class Solution {
public:
   long long solve(string &s,int k){
    map<char,int>mp;
    long long ans=0;
    int cnt=0;
    int n=s.size();
    int j=0;
    for(int i=0;i<n;++i){
        if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
            mp[s[i]]++;
        }
        else cnt++;
        while(cnt>=k && mp['a']>=1 && mp['e']>=1 && mp['i']>=1 && mp['o']>=1 && mp['u']>=1){
            ans+=(n-i);
            if(s[j]=='a' || s[j]=='e' || s[j]=='i' || s[j]=='o' || s[j]=='u')mp[s[j]]--;
            else cnt--;
            j++;
        }
        //cout<<ans<<" ";
    }
    //cout<<endl;
    return ans;
   }
    long long countOfSubstrings(string word, int k) {
        long long x=solve(word,k);
        long long y=solve(word,k+1);
       // cout<<x<<" "<<y<<endl;
        return x-y;
    }
};