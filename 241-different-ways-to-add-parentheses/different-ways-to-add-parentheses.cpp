class Solution {
public:
   map<pair<int,int>,vector<int>>dp;
   vector<int> solve(int i,int j,string &str){
       if(j-i+1<=2)return {stoi(str.substr(i,j-i+1))};

       if(dp.find({i,j})!=dp.end())return dp[{i,j}];
       vector<int>ans;
       for(int k=i;k<=j;++k){
           if(!(str[k]>='0' && str[k]<='9')){
               vector<int>left=solve(i,k-1,str);
               vector<int>right=solve(k+1,j,str);

               if(str[k]=='+'){
                   for(auto x:left){
                       for(auto y:right){
                           ans.push_back(x+y);
                       }
                   }
               }
               else if(str[k]=='-'){
                   for(auto x:left){
                       for(auto y:right){
                           ans.push_back(x-y);
                       }
                   }
               }
               else if(str[k]=='*'){
                   for(auto x:left){
                       for(auto y:right){
                           ans.push_back(x*y);
                       }
                   }
               }
           }
       }
       return dp[{i,j}]=ans;
   }
    vector<int> diffWaysToCompute(string expression) {
       int n=expression.size();
       return solve(0,n-1,expression);
    }
};