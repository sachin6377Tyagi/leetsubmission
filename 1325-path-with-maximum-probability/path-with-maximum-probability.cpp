class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        unordered_map<int,list<pair<int,double>>>adj;
        for(int i=0;i<edges.size();++i){
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        unordered_map<int,bool>vis;
        vector<double>prob(n,0.0);
        priority_queue<pair<double,int>>st;
        st.push({1.0,start_node});
        prob[start_node]=1.0;

        while(!st.empty()){
            auto it=st.top();
            int node=it.second;
            double succ=it.first;
            st.pop();

            for(auto nbr:adj[node]){
                int child=nbr.first;
                double pr=nbr.second;
                double x=(succ*pr);
                // cout<<succ<<" "<<pr<<endl;
                if(x>prob[child]){
                    prob[child]=x;
                    st.push({prob[child],child});
                }
            }
        }
        return prob[end_node];
    }
};