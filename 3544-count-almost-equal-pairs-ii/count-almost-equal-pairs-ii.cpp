class Solution {
public:
   void numToDig(vector<int>&dig,int x){
    int i=6;
    while(i>=0 && x>0){
        dig[i]=x%10;
        x=x/10;
        i--;
    }
   }

   int digToNum(vector<int>&dig){
    int num=0;
    for(int i=0;i<7;++i){
        num=(num*10)+dig[i];
    }
    return num;
   }

    int countPairs(vector<int>& nums) {
       int n=nums.size();
       int ans=0;
       unordered_map<int,int>mp;
       for(int i=0;i<n;++i){
        ans+=mp[nums[i]];
        vector<int>dig(7,0);
        numToDig(dig,nums[i]);
        unordered_set<int>st;
        for(int l1=0;l1<7;++l1){
            for(int r1=l1+1;r1<7;++r1){
                swap(dig[l1],dig[r1]);
                st.insert(digToNum(dig));
                swap(dig[l1],dig[r1]);
                for(int l2=0;l2<7;++l2){
                    for(int r2=l2+1;r2<7;++r2){
                        swap(dig[l1],dig[r1]);
                        swap(dig[l2],dig[r2]);
                        st.insert(digToNum(dig));
                        swap(dig[l2],dig[r2]);
                        swap(dig[l1],dig[r1]);
                    }
                }
            }
        }
        for(auto it:st)mp[it]++;
       } 
       return ans;
    }
};