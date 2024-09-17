class Solution {
public:
   void update(int ind,int lo,int hi,int i,int val,vector<int>&seg){
    if(lo==hi){
        seg[ind]=val;
        return;
    }
    int mid=(lo+hi)/2;
    if(i<=mid)update(2*ind+1,lo,mid,i,val,seg);
    else update(2*ind+2,mid+1,hi,i,val,seg);
    seg[ind]=min(seg[2*ind+1],seg[2*ind+2]);
   }

   int querry(int ind,int lo,int hi,int l,int r,vector<int>&seg){
    if(lo>r || hi<l)return 1e9;
    if(l<=lo && hi<=r)return seg[ind];

   int mid=(lo+hi)/2;
    int left=querry(2*ind+1,lo,mid,l,r,seg);
    int right=querry(2*ind+2,mid+1,hi,l,r,seg);
    return min(left,right);
   }

   vector<int>zFunc(string &s){
    int n=s.size();
    vector<int>z(n,0);
    int l=0,r=0;
    for(int i=1;i<n;++i){
        if(i<r){
            z[i]=z[i-l];
            if(i+z[i]>r)z[i]=r-i;
        }
        while(i+z[i]<n && s[z[i]]==s[i+z[i]])z[i]++;
        if(i+z[i]>r){
            l=i;
            r=i+z[i];
        }
    }
    return z;
   }

   void match(vector<string>& words, string &target,vector<int>&arr){
    for(auto a:words){
        string s=a+"$"+target;
        vector<int>z=zFunc(s);
        for(int i=0;i<target.size();++i)arr[i]=max(arr[i],z[i+a.size()+1]);
    }
   }

    int minValidStrings(vector<string>& words, string target) {
        int n=target.size();
       vector<int>longestMatch(n,0);
       match(words,target,longestMatch); 
       vector<int>seg(4*(n+1),1e9);
       update(0,0,n,n,0,seg);
       //for(int i=0;i<n;++i)cout<<longestMatch[i]<<" ";
       for(int i=n-1;i>=0;i--){
        int len=longestMatch[i];
        if(len==0)continue;
        int qr=querry(0,0,n,i+1,i+len,seg);
        update(0,0,n,i,qr+1,seg);
       }
      // int ans=seg[0];
      int ans=querry(0,0,n,0,0,seg);
       if(ans==1e9)return -1;
       return ans;
    }
};