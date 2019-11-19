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
int isp[N],p[N];
int sz=0;
void init()
{
    
    for(int i=2;i<N;i++)
    {
        if(!isp[i])p[++sz]=i;
         for(int j=1;j<=sz&&(LL)i*p[j]<N;j++)
         {
            isp[i*p[j]]=1;
            if(i%p[j]==0) break;
        }
    }
}
int main(int argc, char const *argv[])
{
    init();
    // for(int i=1;i<10;i++) cout<<p[i]<<endl;
    LL n,m;
    cin>>n; m=n; int ans;
    if (n==1){
        puts("1"); return 0;
    }
    for(int i=1;i<=sz;i++) if (n%p[i]==0){
        while(n%p[i]==0) n/=p[i];
        ans=p[i];
        break;
    }
    if (n==1) {
        cout<<ans<<endl;
        return 0;
    }
    if (n==m) {
        cout<<n<<endl;
        return 0;
    }
    cout<<1;

    return 0;
}