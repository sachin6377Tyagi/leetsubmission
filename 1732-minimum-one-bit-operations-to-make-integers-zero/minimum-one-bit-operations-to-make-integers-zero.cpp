class Solution {
public:
    int minimumOneBitOperations(int n) {
        vector<long long>vec(31);
        vec[0]=1;
        for(int i=1;i<31;++i){
            vec[i]=2*vec[i-1]+1;
        }
        long long ans=0;
        bool flag=0;
        for(int i=30;i>=0;i--){
            if((1<<i)&n){
                if(!flag){
                    ans+=vec[i];
                    flag=1;
                }
                else{
                    ans-=vec[i];
                    flag=0;
                }
            }
        }
        return (int)ans;
    }
};