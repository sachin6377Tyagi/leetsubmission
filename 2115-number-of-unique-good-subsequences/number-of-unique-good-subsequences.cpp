class Solution {
public:
    int numberOfUniqueGoodSubsequences(string binary) {
        int N=1e9+7;
        long long endWithZero=0,endWithOne=0;
        bool flag=0;
        for(auto a:binary){
            if(a=='1'){
                endWithOne=(endWithOne+endWithZero+1)%N;
            }
            else{
                flag=1;
                endWithZero=(endWithOne+endWithZero)%N;
            }
        }
        return (endWithOne+endWithZero+flag)%N;
    }
};