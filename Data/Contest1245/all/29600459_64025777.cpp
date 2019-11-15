#include <bits/stdc++.h>

using namespace std;
long long mod=1000000007,res=1,f[2000000];
bool kt;
string s;
void build()
{
    f[0]=1;
    f[1]=1;
    f[2]=2;
    for(int i=3;i<=100000;i++)
        f[i]=(f[i-1]+f[i-2])%mod;
}
void solve()
{
    long i=0;
    while(i<(long)s.length())
    {
        if(s[i]=='w'||s[i]=='m') kt=true;
        long r=0;
        while(i<(long)s.length()&&s[i]=='u')
            {
                r++;
                i++;
            }
        res=(res*f[r])%mod;
        r=0;
        while(i<(long)s.length()&&s[i]=='n')
            {
                r++;
                i++;


            }
        res=(res*f[r])%mod;
        r=0;
        if(s[i]!='u'&&s[i]!='n')
        i++;
    }
    if(kt)
    cout<<0;
    else cout<<res;
}
int main()
{
     ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    build();
    cin>>s;
    solve();

}
