#include<bits/stdc++.h>
#define int long long

using namespace std;

const int N=1e5+5;
const int mod=1e9+7;

string s;
int n,f[N];

int calc(int x)
{
    if(x==1) return 1;
    if(x==2) return 2;
    if(f[x]!=-1) return f[x];
    int &res=f[x];
    res=(calc(x-2)+calc(x-1))%mod;
    return res;
}

main()
{
    memset(f,-1,sizeof f);
    cin>>s;
    n=s.size();
    s=" "+s;
    int res=1;
    for(int i=1;i<=n;i++)
    {
        char cur=s[i];

        if(cur=='m'||cur=='w') return cout<<0,0;
        if(cur!='u'&&cur!='n') continue;
        int j=i,dem=0;
        while(s[j]==cur)
        {
            j++;
            dem++;
        }
        res=(res*calc(dem))%mod;
        j--;
        i=j;
    }
    cout<<res;
}
