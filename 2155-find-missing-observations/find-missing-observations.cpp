class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sum=0,m=rolls.size();
        for(int i=0;i<m;++i)sum+=rolls[i];
        int total=mean*(n+m);
        int left=total-sum;
        //cout<<total<<endl;
        vector<int>ans;
        if((left/n)<=0 || (left/n)>6 || ((left/n)==6 && (left%n>0)))return ans;
        int num=left/n,rem=left%n;
        for(int i=0;i<n;++i){
            ans.push_back(num+(rem<=0?0:1));
            rem--;
        }
        return ans;
    }
};