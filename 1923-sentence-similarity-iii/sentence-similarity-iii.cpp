class Solution {
public:
    bool areSentencesSimilar(string sent1, string sent2) {
        int n=sent1.size(),m=sent2.size();
        if(n<m)swap(sent1,sent2);
        unordered_set<string>st;
        vector<string>v1,v2;
        string temp="";
        for(int i=0;i<sent1.size();++i){
            if(sent1[i]==' '){
                st.insert(temp);
                v1.push_back(temp);
                temp="";
            }
            else temp+=sent1[i];
        }
        st.insert(temp);
        v1.push_back(temp);
        temp="";
        for(int i=0;i<sent2.size();++i){
            if(sent2[i]==' '){
                if(st.find(temp)==st.end())return false;
                v2.push_back(temp);
                temp="";
            }
            else temp+=sent2[i];
        }
        if(st.find(temp)==st.end())return false;
        v2.push_back(temp);
        int cnt=0,flag=0;
        int i=0,j=0;
        bool ans=1;
        while(i<v1.size() && j<v2.size()){
            if(v1[i]==v2[j]){
                i++;
                j++;
                if(cnt)flag=1;
            }
            else if(flag==0 && v1[i]!=v2[j]){
                cnt++;
                i++;
            }
            else if(flag){
                ans=0;
                break;
            }
        }
        if(i==v1.size() && j<v2.size() && v1.size()==v2.size())return false;
        if(i<v1.size() && flag==1)ans=0;
        if(i==v1.size() && flag==1 && j<v2.size())ans=0;
        if(!ans){
            bool f1=1;
            flag=0;
            i=v1.size()-1,j=v2.size()-1;
            int cnt=0;
            while(i>=0 && j>=0){
                if(v1[i]==v2[j]){
                    i--,j--;
                    if(cnt)flag=1;
                }
                else if(flag==0 && v1[i]!=v2[j]){
                    i--;
                    cnt++;
                }
                else if(flag){
                    f1=0;
                    break;
                }
            }
            if(i>=0 && flag)f1=0;
            if(i<0 && flag==1 && j>=0)f1=0;
            ans=ans|f1;
        }
        return ans;
    }
};