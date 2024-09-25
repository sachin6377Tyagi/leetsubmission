class Solution {
public:
vector<vector<string>>ans;
unordered_map<string,int>mp;
  void dfs(string &word, vector<string>&seq,string &b){
    if(word==b){
        reverse(seq.begin(),seq.end());
        ans.push_back(seq);
        reverse(seq.begin(),seq.end());
        return;
    }
    int step=mp[word];
    for(int i=0;i<word.size();++i){
        char c=word[i];
        for(int j='a';j<='z';++j){
            word[i]=j;
            if(mp.find(word)!=mp.end() && mp[word]+1==step){
               seq.push_back(word);
               dfs(word,seq,b);
               seq.pop_back();
            }
        }
        word[i]=c;
    }
  }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st(wordList.begin(),wordList.end());
        queue<string>q;
        q.push(beginWord);
        st.erase(beginWord);
        mp[beginWord]=1;
        while(q.size()){
            string s=q.front();
            q.pop();
            int step=mp[s];
            if(s==endWord)break;
            for(int i=0;i<s.size();++i){
                char c=s[i];
                for(int j='a';j<='z';++j){
                    s[i]=j;
                    if(st.find(s)!=st.end()){
                        mp[s]=step+1;
                        q.push(s);
                        st.erase(s);
                    }
                }
                s[i]=c;
            }
        }
        if(mp.find(endWord)!=mp.end()){
            vector<string>seq;
            seq.push_back(endWord);
            dfs(endWord,seq,beginWord);
        }
        return ans;
    }
};