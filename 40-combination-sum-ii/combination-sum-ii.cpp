class Solution {
public:
   void solve(int i,vector<int>&arr,int target,vector<int>&output,vector<vector<int>>&ans){
       if(i>=arr.size() || target<=0){
           if(target==0)ans.push_back(output);
           return;
       }

       for(int j=i;j<arr.size();++j){
           if(j!=i && arr[j]==arr[j-1])continue;

           output.push_back(arr[j]);
           solve(j+1,arr,target-arr[j],output,ans);
           output.pop_back();
       }
   }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>output;
        sort(candidates.begin(),candidates.end());
        solve(0,candidates,target,output,ans);
        return ans;
    }
};