class Solution {
public:
    int maxDistance(vector<vector<int>>& arr) {
        pair<int,int>a={1e9,-1};
        pair<int,int>b={1e9,-1};
        pair<int,int>c={-1e9,-1};
        pair<int,int>d={-1e9,-1};
        for(int i=0;i<arr.size();++i){
            int m=arr[i].size();
            pair<int,int>p1={arr[i][0],i};
            pair<int,int>p2={arr[i][m-1],i};
            if(arr[i][0]<a.first){
                b=a;
                a=p1;
            }
            else if(arr[i][0]>=a.first && arr[i][0]<b.first)b=p1;
            if(c.first<arr[i][m-1]){
                d=c;
                c=p2;
            }
            else if(c.first>=arr[i][m-1] && d.first<arr[i][m-1])d=p2;
        }
        if(a.second!=c.second)return c.first-a.first;
        else return max(c.first-b.first,d.first-a.first);
    }
};