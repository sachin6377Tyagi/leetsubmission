class Solution {
public:
    string shortestPalindrome(string s) {
        int n=s.size();
        string match=s+'$';
        string t=s;
        reverse(t.begin(),t.end());
        match+=t;
        int m=match.size();
        vector<int>kmp(m);
        for(int i=1;i<m;++i){
            int j=kmp[i-1];
            //if(i>n)cout<<j<<endl;
            while(j>0 && match[i]!=match[j])j=kmp[j-1];
            if(match[i]==match[j])j++;
            kmp[i]=j;
        }
        //for(int i=0;i<n;++i)cout<<kmp[i+n+1]<<" ";
        string temp=s.substr(kmp[m-1],n-kmp[m-1]);
        reverse(temp.begin(),temp.end());
        return temp +s;
    }
};