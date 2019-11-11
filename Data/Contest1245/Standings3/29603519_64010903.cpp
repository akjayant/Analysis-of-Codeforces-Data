#include<bits/stdc++.h>

#define file ""
#define el cout<<"\n"
#define	f0(i,n) for(int i=0;i<n;i++)
#define f1(i,n) for(int i=1;i<=n;i++)
#define maxn 100005
#define MOD 1000000007

using namespace std;
string s;
int a[maxn], t, cnt;
char b[maxn];
long long ans=1, f[maxn];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ///freopen(file".inp","r",stdin);
    ///freopen(file".out","w",stdout);
    cin >> s;
    int n=s.length();
    s=' '+s+' ';
    f1 (i, n+1)
    {
        if (s[i]=='m'||s[i]=='w') return cout << 0, 0;
        if (s[i]!=s[i-1])
        {
            a[t]=cnt;
            b[t++]=s[i-1];
            cnt=1;
        }
        else cnt++;
    }
    f[1]=1; f[2]=2;
    for (int i=3; i<=n; i++)
        f[i]=(f[i-1]+f[i-2])%MOD;
    f1 (i, t)
    {
        if (b[i]=='u'||b[i]=='n')
        {
            ans = (ans * f[a[i]])%MOD;
            //cout << a[i] << ' ' << b[i]; el;
        }
    }
    cout << ans;
    return 0;
}
