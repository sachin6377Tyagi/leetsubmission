class Solution {
public:
    int minBitFlips(int start, int goal) {
        if(start==0 && goal==0)return 0;
        int ans=0;
        int n=max(floor(log2(start)),floor(log2(goal)));
        for(int i=0;i<=n;++i){
            //cout<<(start & (1<<i))<<" "<<(goal & (1<<i))<<endl;
            if((start & (1<<i))!=(goal & (1<<i)))ans++;
        }
        return ans;
    }
};