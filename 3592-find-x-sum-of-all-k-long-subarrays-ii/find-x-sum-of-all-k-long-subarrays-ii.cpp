class Solution {
public:
  long long sum=0;
  set<pair<long long,long long>>selected,waitlist;
  void remove(pair<long long,long long>&p){
    if(waitlist.find(p)!=waitlist.end()){
        waitlist.erase(p);
    }
    if(selected.find(p)!=selected.end()){
        selected.erase(p);
        sum-=(p.first*p.second);
        if(!waitlist.empty()){
            auto p1=*waitlist.rbegin();
            waitlist.erase(p1);
            selected.insert(p1);
            sum+=(p1.first*p1.second);
        }
    }
  }
  void add(pair<long long,long long>&p,int x){
    selected.insert(p);
    sum+=(p.first*p.second);
    if(selected.size()>x){
        auto p1=*selected.begin();
        selected.erase(p1);
        sum-=(p1.first*p1.second);
        waitlist.insert(p1);
    }
  }
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        map<long long,long long>mp;
         vector<long long>ans;
        int i=0,j=0,n=nums.size();
        while(j<n){
            pair<long long,long long>p={mp[nums[j]],nums[j]};
            if(mp[nums[j]]>0){
                remove(p);
            }
            mp[nums[j]]++;
            p={mp[nums[j]],nums[j]};
            add(p,x);
            if(j-i+1==k){
                ans.push_back(sum);
                p={mp[nums[i]],nums[i]};
                remove(p);
                mp[nums[i]]--;
                if(mp[nums[i]]>0){
                    p={mp[nums[i]],nums[i]};
                    add(p,x);
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};