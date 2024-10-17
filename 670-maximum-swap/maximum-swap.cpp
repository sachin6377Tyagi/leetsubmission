static bool cmp(pair<int,int>&a,pair<int,int>&b){
    if(a.first==b.first)return a.second<b.second;
    return a.first>b.first;
};
class Solution {
public:
    int maximumSwap(int num) {
        if(num==0)return 0;
        vector<int>vec;
        while(num){
            vec.push_back(num%10);
            num=num/10;
        }
        reverse(vec.begin(),vec.end());
        vector<pair<int,int>>arr;
        for(int i=0;i<vec.size();++i)arr.push_back({vec[i],i});
        sort(arr.begin(),arr.end(),cmp);
        int ind=-1;
        for(int i=0;i<vec.size();++i){
            if(arr[i].second!=i){
                ind=i;
                break;
            }
        }
        if(ind!=-1){
            int maxi=vec[ind],i1=ind;
            for(int i=ind+1;i<vec.size();++i){
                if(vec[i]>=maxi){
                    maxi=vec[i];
                    i1=i;
                }
            }
            swap(vec[ind],vec[i1]);
        }
         //reverse(vec.begin(),vec.end());
         int ans=0;
         for(int i=0;i<vec.size();++i){
            ans=(ans*10)+vec[i];
         }
         return ans;
    }
};