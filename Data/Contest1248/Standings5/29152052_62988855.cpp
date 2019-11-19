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

int n;
LL a[N],s;
LL f(LL x) {
    return x*x+(s-x)*(s-x);
}

int main()
{
    while(~scanf("%d",&n)) {
        s=0LL;
        inc(i,1,n) {
            scanf("%lld",&a[i]); s+=a[i];
        }
        sort(a+1,a+1+n);
        LL s1=0LL;
        inc(i,1,n/2) s1+=a[i];
        LL s2=s-s1;
        LL ans=max(f(s1),f(s2));
        printf("%lld\n",ans);
    }

    return 0;
}
