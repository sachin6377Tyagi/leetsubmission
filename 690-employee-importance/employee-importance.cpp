/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
   int dfs(int node,unordered_map<int,bool>&vis,vector<Employee*> &emp,map<int,int>&mp){
    int ans=emp[mp[node]]->importance;
    vis[mp[node]]=1;
    for(auto nbr:emp[mp[node]]->subordinates){
       if(vis[mp[nbr]]) continue;
        int num=dfs(nbr,vis,emp,mp);
        // num+=emp[nbr]->importance;
        ans+=num;
    }
    return ans;
   }
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int,bool>vis;
        map<int,int>mp;
        for(int i=0;i<employees.size();++i)mp[employees[i]->id]=i;
        return dfs(id,vis,employees,mp);
    }
};