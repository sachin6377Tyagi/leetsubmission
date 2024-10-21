class Solution {
public:
   int solve(int i,string &s,string temp,set<string>&st){
    if(i==s.size()){
        if( st.find(temp)==st.end())return 1;
        else return 0;
    }
    int ans=solve(i+1,s,temp+s[i],st);
    if(temp.size()>0 && st.find(temp)==st.end()){
        string x=temp;
        temp="";
        st.insert(x);
        cout<<i<<" "<<x<<endl;
        ans=max(ans,1+solve(i+1,s,temp+s[i],st));
        st.erase(x);
    }
    return ans;
   }
    int maxUniqueSplit(string s) {
        set<string>st;
        string temp="";
        return solve(0,s,temp,st);
    }
};