class Solution {
public:
    int findComplement(int num) {
        int ans=0;
        for(int i=0;i<=log2(num);++i){
            int x=(1<<i);
            if((x&num)==0)ans=(ans|x);
        }
        return ans;
    }
};