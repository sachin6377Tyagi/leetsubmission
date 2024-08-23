class Solution {
public:
   int gcd(int a,int b){
    if(b==0)return a;
    return gcd(b,a%b);
   }

   pair<int,int>solve(vector<int>&arr){
    int n=arr.size();
    if(n==0)return {0,0};
    int lcm=arr[1];
    for(int i=3;i<n;i+=2){
        lcm=((arr[i]*lcm))/(gcd(arr[i],lcm));
    }
    int sum=0;
    for(int i=0;i<n;i+=2){
        int mul=lcm/arr[i+1];
        sum+=(arr[i]*mul);
    }
    pair<int,int>ans;
    if(sum%lcm==0){
        ans.first=sum/lcm;
        ans.second=1;
    }
    else{
        int x=gcd(sum,lcm);
        ans.first=sum/x;
        ans.second=lcm/x;
    }
    return ans;
   }
    string fractionAddition(string exp) {
        int n=exp.size(),i=0;
        vector<int>pos;
        vector<int>neg;
        if(exp[0]!='-'){
            if(exp[i]=='1' && exp[i+1]=='0'){
                pos.push_back(10);
                i++;
            }
            else pos.push_back(exp[i]-'0');
            if(exp[i+2]=='1' && exp[i+3]=='0'){
                pos.push_back(10);
                i++;
            }
            else pos.push_back(exp[i+2]-'0');
            i+=3;
        }
        while(i<n){
            cout<<exp[i]<<" ";
            int j=0;
            int d1,d2;
            if(exp[i+1+j]=='1' && exp[i+2+j]=='0'){
                d1=10;
                j++;
            }
            else d1=exp[i+1+j]-'0';
            if(exp[i+3+j]=='1' && i+j+4<n && exp[i+4+j]=='0'){
                d2=10;
                j++;
            }
            else d2=exp[i+3+j]-'0';
            if(exp[i]=='-'){cout<<d1<<" "<<d2<<endl;
                neg.push_back(d1);
                neg.push_back(d2);
            }
            else{
                pos.push_back(d1);
                pos.push_back(d2);
            }
            i+=4+j;
        }
        // cout<<pos.size()<<endl;
        // for(int i=0;i<pos.size();++i)cout<<pos[i]<<" ";
        pair<int,int>a=solve(pos);
        pair<int,int>b=solve(neg);
        //cout<<a.first<<" "<<a.second<<" "<<b.first<<" "<<b.second<<endl;
        if(a.first==0){
            string ans="";
            ans+='-';
            ans+=to_string(b.first);
            ans+='/';
            ans+=to_string(b.second);
            return ans;
        }
        else if(b.first==0){
            string ans="";
            ans+=to_string(a.first);
            ans+='/';
            ans+=to_string(a.second);
            return ans;
        }
        else{
            int lcm=(a.second*b.second)/gcd(a.second,b.second);
            int q1=lcm/a.second;
            a.first=a.first*q1;
            int q2=lcm/b.second;
            b.first=q2*b.first;
            int d=abs(a.first-b.first);
            if(d%lcm==0){
                d=d/lcm;
                lcm=1;
            }
            int x=gcd(d,lcm);
            d=d/x;
            lcm=lcm/x;
            string ans="";
            if(b.first>a.first)ans+='-';
            ans+=to_string(d);
            ans+='/';
            ans+=to_string(lcm);
            return ans;
        }
        // string ans="";
        // return ans;
    }
};