#include<bits/stdc++.h>
#define N 1000010
#define INF 0x3f3f3f3f
#define eps 1e-6
#define pi acos(-1.0)
#define mod 998244353
#define P 1000000007
#define LL long long
#define pb push_back
#define fi first
#define se second
#define cl clear
#define si size
#define lb lower_bound
#define ub upper_bound
#define bug(x) cerr<<#x<<"      :   "<<x<<endl
#define mem(x) memset(x,0,sizeof x)
#define sc(x) scanf("%d",&x)
#define scc(x,y) scanf("%d%d",&x,&y)  
#define sccc(x,y,z) scanf("%d%d%d",&x,&y,&z)
using namespace std;

int n,m;
char s[N];
int a[N];

int main(int argc, char const *argv[])
{
    sc(m);
    while(m--){
        int n; sc(n);
        for(int i=1;i<=n;i++) sc(a[i]);
        sort(a+1,a+n+1,greater<int>());
        int ans=1;
        for(int i=2;i<=n;i++) ans=max(ans,min(i,a[i]));
        cout<<ans<<endl;
    }



    return 0;
}