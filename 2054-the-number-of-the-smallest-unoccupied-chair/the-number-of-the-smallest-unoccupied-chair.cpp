class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n=times.size();
        vector<vector<int>>vec(n,vector<int>(3));
        for(int i=0;i<n;++i){
            vec[i][0]=times[i][0];
            vec[i][1]=times[i][1];
            vec[i][2]=i;
        }
        sort(vec.begin(),vec.end());
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<n;++i)pq.push(i);
        vector<int>num(n);
        unordered_map<int,vector<int>>mp;
        set<int>st;
        for(int i=0;i<n;++i){
            while(!st.empty() && *st.begin()<=vec[i][0]){
                for(auto it:mp[*st.begin()])pq.push(num[it]);
                mp.erase(*st.begin());
                st.erase(st.begin());
            }
            num[vec[i][2]]=pq.top();
            pq.pop();
            mp[vec[i][1]].push_back(vec[i][2]);
            st.insert(vec[i][1]);
        }
        return num[targetFriend];
    }
};