class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int n=arr1.size(),m=arr2.size();
        set<pair<int,int>>st;
        for(int i=0;i<n;++i){
            int x=arr1[i];
            vector<int>vec;
            while(x){
                vec.push_back(x%10);
                x=x/10;
            }
            reverse(vec.begin(),vec.end());
            int num=0;
            for(int i=0;i<vec.size();++i){
                num=(num*10)+vec[i];
                st.insert({num,i+1});
            }
        }
        int ans=0;
        for(int i=0;i<m;++i){
            int x=arr2[i];
            vector<int>vec;
            while(x){
                vec.push_back(x%10);
                x=x/10;
            }
            reverse(vec.begin(),vec.end());
            int num=0;
            for(int i=0;i<vec.size();++i){
                num=(num*10)+vec[i];
                if(st.find({num,i+1})!=st.end())ans=max(ans,i+1);
            }
        }
        return ans;
    }
};