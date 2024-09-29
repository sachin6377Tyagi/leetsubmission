class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n=word1.size(),m=word2.size();
        vector<int>lastSeen(m,-1);
        int j=m-1;
        for(int i=n-1;i>=0;i--){
            if(j>=0 && word1[i]==word2[j]){
                lastSeen[j]=i;
                j--;
            }
        }
        vector<int>ans;
        bool flag=1;
        j=0;
        for(int i=0;i<n;++i){
            if(word1[i]==word2[j]){
                ans.push_back(i);
                j++;
            }
            else{
                if(flag==1 && j==m-1){
                    ans.push_back(i);
                    j++;
                }
                else if(flag==1 && i+1<=lastSeen[j+1]){
                    flag=0;
                    ans.push_back(i);
                    j++;
                }
            }
            if(j==m)break;
        }
        //cout<<j;
        if(j<m)return {};
        return ans;
    }
};