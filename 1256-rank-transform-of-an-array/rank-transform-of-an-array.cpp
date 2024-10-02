class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n=arr.size();
        vector<int>vec(arr.begin(),arr.end());
        sort(vec.begin(),vec.end());
        int j=1;
        map<int,int>mp;
        for(int i=0;i<n;++i){
           if(mp.find(vec[i])==mp.end()) {
            mp[vec[i]]=j;
            j++;
           }
        }
        for(int i=0;i<n;++i)arr[i]=mp[arr[i]];
        return arr;
    }
};