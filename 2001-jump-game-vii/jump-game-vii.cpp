class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        queue<int>q;
        int n=s.size();
        if(s[n-1]=='1')return false;
        q.push(0);
        int i=0;
        while(q.size()){
            int j=q.front();
            q.pop();
            if(j==n-1)return true;
            i=max(i,j+minJump);
            while(i<min(n,j+maxJump+1)){
                if(s[i]=='0')q.push(i);
                i++;
            }
        }
        return false;
    }
};