#include <bits/stdc++.h>
using namespace std;

#define base 1000000007
#define N 100007
#define int long long

string s;
int d[N],f[N];

void Fibo()
{
    f[1]=1; f[2]=2;
    for(int i=3; i<N; ++i) f[i]=(f[i-1]+f[i-2]) % base;
}

main()
{
    Fibo();
    cin>>s;
    int n=s.size();
    int cnt=0;
    bool ok=true;
    int h=0;
    while (h<n)
    {
        //cout<<h<<endl;
        if (s[h]=='m' || s[h]=='w') ok=false;
        if (h>0)
        {
            if (s[h]==s[h-1] && (s[h]=='u' || s[h]=='n'))
            {
                d[++cnt]=1;
                while (h<n && s[h]==s[h-1]) { ++d[cnt]; ++h;}
            }
            else ++h;
        }
        else ++h;
    }
    if (!ok) { cout<<0; return 0;}
    int ans=1;
    for(int i=1; i<=cnt; ++i) ans=ans*f[d[i]]%base;
    cout<<ans;
}