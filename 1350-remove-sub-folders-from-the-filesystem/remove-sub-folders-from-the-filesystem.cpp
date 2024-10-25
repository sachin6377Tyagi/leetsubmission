class Solution {
public:
  static bool cmp(string &a,string &b){
    return a.size()<b.size();
  }
    vector<string> removeSubfolders(vector<string>& folder) {
       sort(folder.begin(),folder.end(),cmp); 
       set<string>st;
       //set<string>unique;
       for(auto s:folder){
        bool flag=0;
        string temp="";
        for(int i=0;i<s.size();++i){
            if(s[i]=='/' && temp.size()){
                if(st.find(temp)!=st.end()){
                    flag=1;
                    break;
                }
            }
            temp+=s[i];
        }
        if(flag==0)st.insert(temp);
       }
       vector<string>ans;
       for(auto it:st)ans.push_back(it);
       return ans;
    }
};