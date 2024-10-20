class Solution {
public:
    bool parseBoolExpr(string exp) {
        unordered_map<char,bool>mp;
        mp['f']=0;
        mp['t']=1;
        stack<char>st;
        bool ans;
        for(int i=0;i<exp.size();++i){
            if(exp[i]==',' ||exp[i]=='(')continue;
            if(exp[i]==')'){
                vector<char>temp;
                while(st.top()!='!' && st.top()!='&' && st.top()!='|'){
                    temp.push_back(st.top());
                    st.pop();
                }
                char c=st.top();
                bool prev=mp[temp[0]];
                bool curr;
                for(int i=1;i<temp.size();++i){
                    if(c=='&'){
                        curr=mp[temp[i]];
                        prev=(prev&curr);  
                    }
                    else if(c=='|'){
                        curr=mp[temp[i]];
                        prev=(prev|curr);
                    }
                }
                cout<<prev<<" ";
                if(c=='!'){
                    prev=!prev;
                }
                st.pop();
                if(prev)st.push('t');
                else st.push('f');
            }
            else st.push(exp[i]);
        }
        return mp[st.top()];
    }
};