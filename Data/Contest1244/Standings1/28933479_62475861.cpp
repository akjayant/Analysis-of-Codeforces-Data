#include<bits/stdc++.h>
using namespace std;
inline long long rd() {
    long long x=0;
    bool neg=false;
    char c=getchar();
    while (c!='-'&&(c<'0'||c>'9'))
        c=getchar();
    if (c=='-')
        neg=true, c=getchar();
    while (c>='0'&&c<='9')
        x=x*10+c-'0', c=getchar();
    if (neg)
        x=-x;
    return x;
}
inline void write(long long x) {
    if (x<0) {
        putchar('-');
        x=-x;
    }
    if (x>9)
        write(x/10);
    putchar(x%10+'0');
}
typedef pair<long long,long long> ii;
#define fast_io ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define all(x) x.begin(),x.end()
#define rep(i,x) for(long long _x=x,i=0;i<_x;++i)
#define finc(i,a,b) for(long long _b=b,i=a;i<=_b;++i)
#define fdec(i,a,b) for(long long _b=b,i=a;i>=_b;--i)
#define pb push_back
#define x first
#define y second
#define _ putchar(' ')
#define __ putchar('\n')
const long long N=1e5+2;
long long n,k,a[N],sum[N];
bool check(long long l,long long r) {
    long long L=max(l,1ll),R=r;
    l=lower_bound(a+1,a+n+1,L)-a;
    r=upper_bound(a+1,a+n+1,R)-a;
    --l;
    --r;
    long long S=((r==n+1)?0:sum[n]-sum[r]-R*(n-r))+L*l-sum[l];
    return (S<=k);
}
bool fuck_this_q(long long x) {
    finc(i,1,n) {
        if(check(a[i]-x,a[i])) return 1;
        if(check(a[i],a[i]+x)) return 1;
    }
    return 0;
}
int main() {
    fast_io;
    cin >> n >> k;
    finc(i,1,n) cin >> a[i];
    sort(a+1,a+n+1);
    finc(i,1,n) sum[i]=sum[i-1]+a[i];
    long long l=0,r=1e9,res;
    while(l<=r) {
        long long mid=(l+r)/2;
        if(fuck_this_q(mid)){
            res=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    cout<<res<<"\n";
    return 0;
}
