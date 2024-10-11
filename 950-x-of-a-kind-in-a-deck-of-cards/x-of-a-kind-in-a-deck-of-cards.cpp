class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
      unordered_map<int,int>mp;
      for(int i=0;i<deck.size();++i)mp[deck[i]]++;
      int num=0;
      for(auto it:mp)num=__gcd(it.second,num);
      if(num==1)return false;
      return true;
    }
};