class Solution {
public:
    int minSwaps(string s) {
        int cnt=0;
        for(int i=0;i<s.size();++i){
            if(s[i]=='[')cnt++;
            else{
                if(cnt>0)cnt--;
            }
        }
        return ceil(cnt/2.0);
    }
};