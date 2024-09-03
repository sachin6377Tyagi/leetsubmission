class Solution {
public:
  static bool cmp(pair<long long,long long>&a,pair<long long,long long>&b){
    return a.first*b.second>b.first*a.second;
  }
    long long minDamage(int power, vector<int>& damage, vector<int>& health) {
        long long ans=0;
        int n=damage.size();
        vector<pair<long long,long long>>vec(n);
        for(int i=0;i<n;++i){
            long long q=health[i]/power;
            if(health[i]%power)q++;
            vec[i]={damage[i],q};
        }
        sort(vec.begin(),vec.end(),cmp);
        // for(int i=0;i<n;++i)cout<<vec[i].first<<" "<<vec[i].second<<endl;
        // for(long long i=1;i<n;++i){
        //     long long x=(vec[i-1].first*vec[i].second);
        //     long long y=(vec[i].first*vec[i-1].second);
        //     if(y>x)swap(vec[i],vec[i-1]);
        //     //cout<<x<<" "<<y<<endl;
        // }
       // for(int i=0;i<n;++i)cout<<vec[i].first<<" "<<vec[i].second<<endl;
        long long sum=0;
        for(int i=0;i<n;++i){
            sum+=vec[i].second;
            ans+=(sum*vec[i].first);
        }
        return ans;
    }
};