class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string ans="";
        priority_queue<pair<int,char>>pq;
        if(a>0)pq.push({a,'a'});
        if(b>0)pq.push({b,'b'});
        if(c>0)pq.push({c,'c'});
        while(pq.size()){
            bool f1=0;
            auto x=pq.top();
            pq.pop();
            if(pq.empty()){
                ans+=x.second;
                if(x.first>1)ans+=x.second;
                break;
            }
            auto y=pq.top();
            pq.pop();
            if(x.first-y.first>1)f1=1;
            for(int i=0;i<1+f1;++i)ans+=x.second;
            ans+=y.second;
            if(x.first-1-f1>0)pq.push({x.first-1-f1,x.second});
            if(y.first-1>0)pq.push({y.first-1,y.second});
        }
        return ans;
    }
};