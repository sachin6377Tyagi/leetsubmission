class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
      vector<string>ans;
      int n=s.size();
      map<char,int>mp,temp;
      for(int i=0;i<n;++i){
        mp[s[i]]++;
        temp[s[i]]++;
      } 
      int i=0,j=0;
      while(j<n){
        mp[s[j]]--;
        if(mp[s[j]]==0){
            map<char,int>mp1;
            int x=j;
            while(x>=i){
                mp1[s[x]]++;
                int cnt=0;
                if(temp[s[x]]==mp1[s[x]]){
                    for(auto it:mp1){
                        if(it.second!=temp[it.first])break;
                        cnt+=it.second;
                    }
                }
                if(cnt==j-x+1){
                    string str=s.substr(x,cnt);
                    ans.push_back(str);
                    i=j+1;
                    break;
                }
                x--;
            }
        }
        j++;
      }
      if(ans.size()==0)return {s};
      return ans; 
    }
};