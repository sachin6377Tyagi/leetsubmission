#define ll long long
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define ps push
#define in insert
#define f first
#define s second

const int MOD = 1e9 + 7;
const int p = 373;
ll fpow(ll b, ll p){
    ll r = 1;
    for(; p; p>>=1, b=b*b%MOD) if(p&1) r=r*b%MOD;
    return r;
}
ll minv(ll a) { return fpow(a, MOD-2); }

class Solution {
public:
    int minimumCost(string target, vector<string>& words, vector<int>& costs) {
        int n = target.size();
        vector<ll> pw(n,1);
        vector<ll> rev(n,1);
        unordered_map<ll, int> best;
        set<int> sz;
        for(int i=0; i<words.size(); i++) sz.insert(words[i].size());
        
        for(int i=1; i<n; i++) pw[i] = pw[i-1] * p % MOD;
        for(int i=0; i<n; i++) rev[i] = minv(pw[i]);
        
        ll hsh[n];
        for(int i=0; i<n; i++) {
            hsh[i] = (i ? hsh[i-1] : 0) + pw[i] * (target[i] - 'a' + 1) % MOD;
            hsh[i] %= MOD;
        }
        for(int i=0; i<words.size(); i++) {
            if(words[i].size() > n) {
                continue;
            }
            ll h = 0;
            for(int j=0; j<words[i].size(); j++) {
                h += pw[j] * (words[i][j] - 'a' + 1) % MOD;
                h %= MOD;
            }
            if(best.count(h) == 0) best[h] = costs[i];
            else best[h] = min(best[h], costs[i]);
        }
        
        
        vector<ll> dp(n, -1);
        for(int i=0; i<n; i++){
            ll pv = (i ? dp[i-1] : 0);
            if(pv == -1) continue;
            for(auto x:sz) {
                if(i+x-1 >= n) break;
                ll goal = (hsh[i + x - 1] - (i?hsh[i-1]:0) + MOD) % MOD;
                goal = goal * rev[i] % MOD;
                if(best.count(goal)) {
                    if(dp[i+x-1] == -1) dp[i+x-1] = pv + best[goal];
                    else dp[i+x-1] = min(dp[i+x-1], pv + best[goal]);
                }
            }
        }
        return dp[n-1];
    }
};