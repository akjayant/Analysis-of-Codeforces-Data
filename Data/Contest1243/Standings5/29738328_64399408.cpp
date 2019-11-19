#include<bits/stdc++.h>
#define int long long
#define M 998244353
#define mod 1000000007
#define all(v) v.begin(),v.end()
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
int32_t main(){
ios
int t=1;
//cin>>t;
while(t--)
{
    int n;cin>>n;
    if(n==1){cout<<1;}
    else{
    vector<int> div;
    int i=2;
    int tn=n;
    while(i*i<=n)
    {
        if(n%i==0)
        {
            div.push_back(i);
            while(n%i==0)
            n/=i;
        }
        i+=1;
    }
    if(n>1){div.push_back(n);}
    int sz=div.size();
    int mn=1e18;
    for(int i=0;i<sz;i++)
    {
        for(int j=i;j<sz;j++)
        {
            int g=__gcd(div[i],div[j]);
            mn=min(mn,g);
        }
    }
    if(sz==1)
    {
        if(div[0]==tn)cout<<tn;
        else cout<<div[0];
    }
    else cout<<mn;}
}
}
