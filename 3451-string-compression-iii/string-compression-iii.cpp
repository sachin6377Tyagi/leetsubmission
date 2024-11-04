class Solution {
public:
    string compressedString(string word) {
        vector<pair<char,int>>vec;
        int cnt=1;
        for(int i=1;i<word.size();++i){
            if(word[i]!=word[i-1]){
                vec.push_back({word[i-1],cnt});
                cnt=1;
            }
            else cnt++;
        }
        vec.push_back({word[word.size()-1],cnt});
        string ans="";
        for(int i=0;i<vec.size();++i){
            int x=vec[i].second;
            while(x>0){
                if(x<=9){
                    ans+=to_string(x);
                    ans+=vec[i].first;
                }
                else{
                    ans+=to_string(9);
                    ans+=vec[i].first;
                }
                x=x-9;
            }
        }
        return ans;
    }
};