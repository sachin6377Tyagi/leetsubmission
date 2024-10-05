class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s1.size(),m=s2.size(),i=0,j=0;
        map<char,int>mp1,mp2;
        for(int i=0;i<n;++i)mp1[s1[i]]++;
        while(j<m){
            mp2[s2[j]]++;
            if(j-i+1==n){
                if(mp1==mp2)return true;
                mp2[s2[i]]--;
                if(mp2[s2[i]]==0)mp2.erase(s2[i]);
                i++;
            }
            j++;
        }
        return false;
    }
};