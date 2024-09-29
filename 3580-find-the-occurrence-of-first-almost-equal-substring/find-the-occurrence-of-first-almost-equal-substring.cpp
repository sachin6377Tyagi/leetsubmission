class Solution {
public:
    int minStartingIndex(string s, string pat) {
        int n=s.size(),m=pat.size();
        vector<int>z1(n+m+1,0);
        vector<int>z2(n+m+1,0);
        string str=pat+'#'+s;
        int l=0,r=0;
        for(int i=1;i<str.size();++i){
            if(i<r){
                z1[i]=z1[i-l];
                if(i+z1[i]>r)z1[i]=r-i;
            }
            while(i+z1[i]<str.size() && str[z1[i]]==str[i+z1[i]])z1[i]++;
            if(i+z1[i]>r){
                r=i+z1[i];
                l=i;
            }
        }
        reverse(s.begin(),s.end());
        reverse(pat.begin(),pat.end());
        str=pat+'#'+s;
        l=0,r=0;
        for(int i=1;i<str.size();++i){
            if(i<r){
                z2[i]=z2[i-l];
                if(i+z2[i]>r)z2[i]=r-i;
            }
            while(i+z2[i]<str.size() && str[z2[i]]==str[i+z2[i]])z2[i]++;
            if(i+z2[i]>r){
                r=i+z2[i];
                l=i;
            }
        }
        //for(int i=m+1;i<z1.size();++i)cout<<z1[i]<<' '<<z2[i]<<endl;
        for(int i=m+1;i<z1.size();++i){
            int x=(n+m+1)-(i+m);
            if(x>=0){
                if(z1[i]+z2[x+m+1]>=(m-1))return i-(m+1);
            }
        }
        return -1;
    }
};