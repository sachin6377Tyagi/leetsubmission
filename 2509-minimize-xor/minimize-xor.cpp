class Solution {
public:
    int minimizeXor(int num1, int num2) {
      int cnt=0;
      for(int i=31;i>=0;i--){
        if(num2&(1<<i))cnt++;
      } 
      int ans=0;
      for(int i=31;i>=0;i--){
        if(cnt==0)break;
        if(num1&(1<<i)){
            ans+=(1<<i);
            cnt--;
        }
      }
      if(cnt>0){
        for(int i=0;i<32;++i){
            if(ans&(1<<i))continue;
            ans+=(1<<i);
            cnt--;
            if(cnt==0)break;
        }
      } 
      return ans;
    }
};