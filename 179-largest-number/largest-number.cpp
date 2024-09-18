static bool cmp(string &a,string &b){
    if(a+b>b+a)return true;
    return false;
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string>vec;
        for(auto a:nums)vec.push_back(to_string(a));
        sort(vec.begin(),vec.end(),cmp);
        if(vec[0]=="0")return "0";
        string ans="";
        for(auto a:vec)ans+=a;
        //for(auto a:vec)cout<<a<<" ";
        return ans;
    }
};