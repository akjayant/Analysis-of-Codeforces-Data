#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+5;
int a[N],b[N],ss[2],tt[2];
void mian()
{
    int n,m;
    ss[0]=ss[1]=tt[0]=tt[1]=0;
    scanf("%d",&n);for(int i=1;i<=n;i++)scanf("%d",&a[i]),ss[a[i]%2]++;
    scanf("%d",&m);for(int i=1;i<=m;i++)scanf("%d",&b[i]),tt[b[i]%2]++;
    ll ans=ss[0]*1ll*tt[0]+1ll*ss[1]*tt[1];
    cout<<ans<<endl;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)mian();
}
