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
cin>>t;
while(t--)
{
    int n;cin>>n;
    string s,t;cin>>s>>t;char diff1,diff2,diff3,diff4;int cnt=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]!=t[i])
        {
            if(cnt==0)
            diff1=s[i],diff2=t[i];
            else if(cnt==1)diff3=s[i],diff4=t[i];
            cnt++;

        }
    }
    if(cnt!=2 and cnt!=0)cout<<"No\n";
    else if(cnt==0)
    {
        cout<<"YES\n";
    }
    else 
    {
        if(diff1==diff3 and diff2==diff4)cout<<"Yes\n";
        else cout<<"No\n";
    }
}
}
