#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
ll test,a,b,c,xx[110];
long double n;
template <typename T> inline void read(T & x)
{
    char c; bool nega=0;
    while((!isdigit(c=getchar()))&&c!='-');
    if(c=='-')
    {
        c=getchar();
        nega=1;
    }
    x=c-48;
    while(isdigit(c=getchar()))
    {
        x=x*10+c-48;
    }
    if(nega) x=-x;
}
template <typename T> void Write(T x) {if (x > 9) Write(x/10); putchar(x%10+48);}
template <typename T> void write(T x) {if (x < 0) {putchar('-'); x = -x;} Write(x);}
const int mod = 1e9 + 7;
ll f[100010];
string s;
vector <ll> ans;
int main()
{
   // freopen("h.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    cin>>s;
    int n=s.size();
    s=" "+s;
    for(int i=1;i <= n; i++)
        if(s[i]=='w'||s[i]=='m')
            cout << 0, exit(0);
    f[1] = 1; f[0] = 1;
    for(int i=2;i<=n;i++)
        f[i]=(f[i-2]+f[i-1])%mod;
    for(int i=1;i<=n;)
    {
        int j=i;
        if(s[i]=='n'||s[i]=='u')
            while(j+1<=n&&s[j+1]==s[i])
                j++;
        ans.push_back(f[j-i+1]);
        i=j+1;
    }
    ll res=1;
    for(int i=0;i<ans.size();i++)
    {
        ll j=ans[i];
        res=(res*j)%mod;
    }
    cout<<res;
}
