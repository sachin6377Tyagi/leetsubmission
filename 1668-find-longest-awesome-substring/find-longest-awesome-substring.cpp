class Solution {
public:
    int longestAwesome(string s) {
        int mask=0;
        map<int,int>mp;
        mp[0]=-1;
        int ans=0;
        for(int i=0;i<s.size();++i){
            mask=mask^(1<<(s[i]-'0'));
            if(mp.find(mask)!=mp.end()){
                ans=max(ans,i-mp[mask]);
            }
            for(int j=0;j<10;++j){
                int newMask=mask^(1<<j);
                if(mp.find(newMask)!=mp.end()){
                    ans=max(ans,i-mp[newMask]);
                }
            }
            if(mp.find(mask)==mp.end())mp[mask]=i;
        }
        return ans;
    }
};