class Solution {
public:
    int robotSim(vector<int>& com, vector<vector<int>>& obst) {
        map<int,unordered_set<int>>visx;
        map<int,unordered_set<int>>visy;
        for(int i=0;i<obst.size();++i){
            visx[obst[i][0]].insert(obst[i][1]);
            visy[obst[i][1]].insert(obst[i][0]);
        }
        long long x=0,y=0, dir=0;
        long long ans=0;
        //bool flag[4]={0,0,0,0};
        for(int num:com){
            if(num==-1){
                dir=(dir+1)%4;
            }
            else if(num==-2){
                dir--;
                if(dir<0)dir+=4;
            }
            else{
                int k=num;
                if(dir==0){
                   int z=y;
                    for(int i=z+1;i<=z+k;i++){
                        if(visx[x].find(i)!=visx[x].end())break;
                         y++;
                    }
                }
                else if(dir==1){
                    int z=x;
                        for(int i=z+1;i<=z+k;++i){
                            if(visy[y].find(i)!=visy[y].end())break;
                             x++;
                        }
                }
                else if(dir==2){
                    int z=y;
                    for(int i=z-1;i>=z-k;--i){
                        if(visx[x].find(i)!=visx[x].end())break;
                        y--;
                    }
                }
                else{
                    int z=x;
                        for(int i=z-1;i>=z-k;i--){
                            if(visy[y].find(i)!=visy[y].end())break;
                            x--;
                        }
                }
            }
            ans=max(ans,(x*x)+(y*y));
        }
        return ans;
    }
};