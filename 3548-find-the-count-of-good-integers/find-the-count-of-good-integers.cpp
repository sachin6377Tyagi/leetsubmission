class Solution {
public:
#define ll long long
   long long ans=0;
   set<map<int,int>>vis;

   long long arrToNum(vector<int>&num){
    long long sum=0;
    for(int i=0;i<num.size();++i){
        sum=sum*1ll*10+num[i];
    }
    return sum;
   }

   ll fact(int n){
        ll sum = 1;
        for(int i=2 ; i<=n ; i++) sum *= i;
        return sum;
    }

   ll perm(map<int, int> &freq, int n) {
        ll totalPermutations = fact(n);

        for (auto i : freq) {
            totalPermutations /= fact(i.second);
        }
        return totalPermutations;
    }

   long long permZero(map<int,int> mp,int n){
    if(mp.find(0)==mp.end() || mp[0]==0)return 0;
    mp[0]--;
    long long sum=fact(n-1);
    for(auto it:mp){
        sum/=fact(it.second);
    }
    return sum;
   }

   long long calc(map<int,int>&mp,int n){
    long long a=perm(mp,n);
    long long b=permZero(mp,n);
    return a-b;
   }

   void generatePalindrome(vector<int>& num, int left, int right, int k, int n){
    if(left>right){
        long long x=arrToNum(num);
        if(x%k==0){
            map<int,int>mp;
            for(int i=0;i<n;++i)mp[num[i]]++;
            if(vis.find(mp)==vis.end()){
                //cout<<x<<endl;
                ans+=calc(mp,n);
                vis.insert(mp);
            }
        }
        return;
    }
    for (int digit = (left == 0) ? 1 : 0; digit <= 9; ++digit){
        num[left] = num[right] = digit;
        generatePalindrome(num, left + 1, right - 1, k, n);
    }
   }
    long long countGoodIntegers(int n, int k) {
        vector<int> num(n);
        generatePalindrome(num, 0, n-1, k, n);
        return ans;
    }
};