#include <bits/stdc++.h>
#define int long long
#define For(i,a,b) for(int i=a;i<=b;++i)
#define fordec(i,a,b) for(int i=a;i>=b;--i)
#define fi first
#define se second
using namespace std;
const int mod=1e9+7,
            N=1e5+10;
string s;
int n;
int pos,pos1,ret=1;
int f[N];

main()
{
    cin>>s;
    n=s.size();
    s=' '+s;
    For(i,1,n) if(s[i]=='m'||s[i]=='w') return cout<<0,0;
    f[0]=1,f[1]=1;
    For(i,2,n) f[i]=(f[i-1]+f[i-2])%mod;
    For(i,1,n)
    {
        if(s[i]!='u') continue; int countt=0;
        while(s[i]=='u')
        {
            countt++; i++;
        }
        if(countt>=2) ret=(ret*f[countt])%mod;
        //i--;
    }
    For(i,1,n)
    {
        if(s[i]!='n') continue; int countt=0;
        while(s[i]=='n')
        {
            countt++;
            i++;
        }
        if(countt>=2) ret=(ret*f[countt])%mod;
    } cout<<ret;
}
