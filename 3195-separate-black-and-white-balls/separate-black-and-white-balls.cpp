class Solution {
public:
    long long minimumSteps(string s) {
       long long ans=0;
       queue<int>st;
       for(int i=0;i<s.size();++i){
        if(s[i]=='1')st.push(i);
        else{
            if(st.empty())continue;
            ans+=(i-st.front());
            st.pop();
            st.push(i);
        }
       } 
       return ans;
    }
};