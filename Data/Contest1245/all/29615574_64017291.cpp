#include <bits/stdc++.h>
#define ll long long
#define N 500000

using namespace std;
const ll mod=1e9+7;
ll kq=1;
ll dem[N],f[N],n,Max;
string s;
main()
{
   // freopen("a.inp","r",stdin);
//    freopen("a.out","w",stdout);
    f[0]=1ll;
    f[1]=1ll;
    //for(ll i=2;i<=10000;i++) f[i]=(f[i-1]+f[i-2])%mod;
    cin>>s;
    for(int i=0;i<s.length();i++)
    {
        if (s[i]=='m' || s[i]=='w') {cout<<0; return 0;}
        if (s[i]==s[i-1]) dem[i]=dem[i-1]+1;
        Max=max(Max,dem[i]);
    }
    for(int i=2;i<=Max+1;i++) f[i]=(f[i-1]+f[i-2])%mod;
    for(int i=0;i<s.length();i++)
    {
        if (s[i]!=s[i+1])
            if (s[i]=='u' || s[i]=='n') kq=(kq*f[dem[i]+1])%mod;
    }
    cout<<kq;
}
