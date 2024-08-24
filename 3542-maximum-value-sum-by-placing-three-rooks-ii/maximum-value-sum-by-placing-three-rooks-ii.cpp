class Solution {
public:
    long long maximumValueSum(vector<vector<int>>& board) {
        int n=board.size(),m=board[0].size();
        vector<vector<long long>>vec;
        for(int i=0;i<n;++i){
            priority_queue<vector<long long>,vector<vector<long long>>,greater<vector<long long>>>pq;
            for(int j=0;j<m;++j){
                pq.push({board[i][j],i,j});
                if(pq.size()>4)pq.pop();
            }
            while(pq.size()){
                vec.push_back(pq.top());
                pq.pop();
            }
        }
        sort(vec.rbegin(),vec.rend());
        long long ans=-1e18;
        int len=vec.size();
        for(int i=0;i<4;++i){
            for(int j=i+1;j<len-1;++j){
                for(int k=j+1;k<len;++k){
                    if(vec[i][1]==vec[j][1] || vec[i][1]==vec[k][1] || vec[j][1]==vec[k][1]
                    || vec[i][2]==vec[j][2] || vec[i][2]==vec[k][2] || vec[j][2]==vec[k][2])continue;
                    long long sum=vec[i][0]+vec[j][0]+vec[k][0];
                    ans=max(ans,sum);
                }
            }
        }
        return ans;
    }
};