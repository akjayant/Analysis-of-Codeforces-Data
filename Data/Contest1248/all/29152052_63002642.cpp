#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define INF 0x3f3f3f3f
#define ULL unsigned long long
#define inc(i,j,k) for(int i=j;i<=k;i++)
#define dec(i,j,k) for(int i=j;i>=k;i--)
#define mem(i,j) memset(i,j,sizeof(i))
#define bug(args...) cout<<#args<<"="<<args<<endl;
const int N=1e5+5;
const int mod=1e9+7;

int n,m;
int a[N];

int main()
{
    a[1]=2,a[2]=4;
    inc(i,3,N-5) a[i]=(a[i-1]+a[i-2])%mod;
    while(~scanf("%d%d",&n,&m)) {
        int ans=((a[n]+a[m])%mod-2+mod)%mod; 
        printf("%d\n",ans);
    }

    return 0;
}
