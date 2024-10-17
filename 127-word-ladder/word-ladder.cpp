class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string>st;
        for(int i=0;i<wordList.size();++i)st.insert(wordList[i]);
        queue<string>q;
        q.push(beginWord);
        unordered_set<string>vis;
        vis.insert(beginWord);
        char arr[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
        int level=1;
        while(!q.empty()){
            int n=q.size();
            while(n--){
                string s=q.front();
                q.pop();
                if(s==endWord)return level;
                for(int i=0;i<26;++i){
                    for(int j=0;j<s.size();++j){
                        if(s[j]==arr[i])continue;
                        string temp=s;
                        temp[j]=arr[i];
                        if(!vis.count(temp)&&st.find(temp)!=st.end()){
                            // cout<<temp<<endl;
                            q.push(temp);
                            vis.insert(temp);
                        }
                    }
                }
            }
            level++;
        }
        return 0;
    }
};