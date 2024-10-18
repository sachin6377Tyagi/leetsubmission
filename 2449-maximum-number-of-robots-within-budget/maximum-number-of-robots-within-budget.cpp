class Solution
{
public:
    bool check(int k, vector<int> &c1, vector<int> &c2, long long b)
    {

        int n=c1.size();
        vector<long long>pre(n+1);
        for(int i=1;i<=n;++i)pre[i]=pre[i-1]+c2[i-1];
        int i=0,j=0;
        priority_queue<pair<int,int>>pq;
        while(j<n){
            pq.push({c1[j],j});
            if(j-i+1==k){
                while(pq.top().second<i)pq.pop();
                long long sum=pq.top().first+k*1ll*(pre[j+1]-pre[i]);
                if(sum<=b)return true;
                i++;
            }
            j++;
        }
        return false;
    }

    int maximumRobots(vector<int> &c1, vector<int> &c2, long long b)
    {
        int n = c1.size();
        int L = 1, R = n, ans = 0;
        while (L <= R)
        {
            int mid = (L + R) / 2;
            if (check(mid, c1, c2, b))
            {
                ans = mid;
                L = mid + 1;
            }
            else
                R = mid - 1;
        }
        return ans;
    }
};