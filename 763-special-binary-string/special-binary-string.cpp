class Solution {
public:
    string makeLargestSpecial(string s) {
        int n=s.size(),cnt=0,start=0;
        vector<string>vec;
        for(int i=0;i<n;++i){
            if(s[i]=='1')cnt++;
            else cnt--;
            if(cnt==0){
                string temp="1"+makeLargestSpecial(s.substr(start+1,i-start-1))+"0";
                vec.push_back(temp);
                start=i+1;
            }
        }
        string ans="";
        sort(vec.rbegin(),vec.rend());
        for(auto it:vec)ans+=it;
        return ans;
    }
};