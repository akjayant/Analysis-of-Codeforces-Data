/// ANTI_LIGHT

#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define f first
#define s second

const int maxn=1e5+100;
const int mod=1e9+7;
int fib[maxn];

bool chec(string st)
{
    for(int i=0;i<st.size();i++)
        if(st[i]=='w' or st[i]=='m')
            return 1;
    return 0;
}

main()
{
    fib[0]=1;
    fib[1]=1;
    fib[2]=2;
    for(int i=3;i<=1e5+10;i++)
        fib[i]=(fib[i-1]+fib[i-2])%mod;

    string st;
    cin>>st;
    if(chec(st))
    {
        cout<<0;
        return 0;
    }

    st=st+'@';
    int ans=1;
    int num=0;
    if(st[0]=='n' or st[0]=='u')
        num++;

    for(int i=1;i<st.size();i++)
    {
        if(st[i]==st[i-1] and (st[i]=='n' or st[i]=='u'))
            num++;
        else
        {
            ans*=fib[num];
            ans=ans%mod;
            num=0;
            if(st[i]=='n' or st[i]=='u')
                num++;
        }
    }
    cout<<ans;

    return 0;
}
