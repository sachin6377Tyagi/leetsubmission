class Solution {
public:
    int minLength(string s) {
       int n=s.size();
       stack<char>st;
       int cnt=0;
       for(int i=0;i<n;++i){
        if(s[i]=='B'){
            if(st.empty() || st.top()!='A')st.push(s[i]);
            else if(st.top()=='A'){
                st.pop();
                cnt+=2;
            }
        }
        else if(s[i]=='D'){
            if(st.empty() || st.top()!='C')st.push(s[i]);
            else if(st.top()=='C'){
                st.pop();
                cnt+=2;
            }
        }
        else st.push(s[i]);
       }
       return st.size(); 
    }
};