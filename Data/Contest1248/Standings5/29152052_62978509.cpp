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

int n,m,p[N],q[N],c1[2],c2[2];

int main()
{
    int _; scanf("%d",&_);
    while(_--) {
        scanf("%d",&n); mem(c1,0); mem(c2,0);
        inc(i,1,n) scanf("%d",&p[i]), c1[p[i]%2]++;
        scanf("%d",&m);
        inc(i,1,m) scanf("%d",&q[i]), c2[q[i]%2]++;
        printf("%lld\n",1LL*c1[0]*c2[0]+1LL*c1[1]*c2[1]);
    }

    return 0;
}
