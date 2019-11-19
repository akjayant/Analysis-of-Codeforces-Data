#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
using namespace std;
typedef long long ll;
const int N=1e6+10;
ll m,n,t;
ll p[N],f[N];
vector<ll> pri;

int main()
{
    // freopen("data.txt","r",stdin);
    scanf("%lld",&n);
    if(n==1)return puts("1"),0;
    for(int i=2;i<=1e6;i++)if(!f[i])
    {
        p[++p[0]]=i;
        for(int j=i;j<=1e6;j+=i)f[j]=1;
    }
    for(int i=1;i<=p[0];i++)if(!(n%p[i]))
    {
        pri.push_back(p[i]);
        while(!(n%p[i]))n/=p[i];
    }
    if(n>1)pri.push_back(n);
    if(pri.size()>1)puts("1");
    else printf("%lld\n",pri[0]);
}
