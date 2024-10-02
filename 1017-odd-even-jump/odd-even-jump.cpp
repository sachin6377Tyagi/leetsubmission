class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
       int n=arr.size();
       vector<bool>odd(n,0);
       vector<bool>even(n,0);
       map<int,vector<int>>mp;
       odd[n-1]=1;
       even[n-1]=1;
       mp[arr[n-1]].push_back(n-1);
       set<int>st;
       st.insert(arr[n-1]);
       for(int i=n-2;i>=0;i--){
        auto it1=st.lower_bound(arr[i]);
        if(it1!=st.end()){
            int ind=mp[*it1].back();
            if(even[ind])odd[i]=1;
        }
        auto it2=st.upper_bound(arr[i]);
        if(it2!=st.begin()){
            it2--;
            int ind=mp[*it2].back();
            if(odd[ind])even[i]=1;
        }
        mp[arr[i]].push_back(i);
        st.insert(arr[i]);
       } 
       int ans=0;
       for(int i=0;i<n;++i){
        if(odd[i])ans++;
       }
       return ans;
    }
};