#include <bits/stdc++.h>
using namespace std;
#define sc(x)            scanf("%d",&x)
#define scc(x)           scanf("%c",&x)
#define scl(x)           scanf("%lld",&x)
#define sz(v)	     	(v.size())
#define mem(v, d)		memset(v, d, sizeof(v))
#define oo				2000000100
#define OO				2000000000000000100
#define PI 3.14159265
#define s second
#define f first
#define Ceil(x,y) ((x+y-1)/y)
#define EPS 1e-8
#define IO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
const double pi=3.14159265358979323846264338327950288419716939937510582097494459;
typedef unsigned int uint;
typedef long long ll;
int dX[] = {0,0,1,-1,0};
int dY[] = {1,-1,0,0,0};
string alpha = "abcdefghijklmnopqrstuvwxyz";
const int N = 100100;
const int MOD = 1e9 + 7;
int n,arr[N]; ll k,sum[N];
int bs(int tar)
{
    int l = 0,r = n,mid;
    while(l<r)
    {
        mid = l+(r-l+1)/2;
        if(arr[mid]<=tar) l = mid;
        else r = mid-1;
    }
    return l;
}
bool ok(int m)
{
    for(int i = 1;i<=n;++i)
    {
        ll pre = 0,nxt = 0;
        int idx = lower_bound(arr+1,arr+n+1,arr[i]+m) - arr;
        pre = i*1LL*arr[i]-sum[i];
        if(idx <= n) nxt = (sum[n] - sum[idx-1]) - (n - idx + 1)*1LL*(arr[i]+m);

        if(pre+nxt <= k) return 1;
    }
    for(int i = n;i;--i)
    {
        ll pre = 0,nxt = 0;
        int idx = bs(arr[i]-m);
        if(idx) pre = idx*1LL*(arr[i]-m)-sum[idx];
        nxt = (sum[n] - sum[i-1]) - (n - i + 1)*1LL*(arr[i]);
        if(pre+nxt <= k) return 1;
    }
    return 0;
}
int main()
{
#ifndef ONLINE_JUDGE
      //freopen("in.txt","r",stdin);
#else
    //freopen("journey.in","r",stdin);
    //freopen("journey.out","w",stdout);
#endif
    sc(n); scl(k);
    for(int i = 1;i<=n;++i)
        sc(arr[i]);
    sort(arr+1,arr+n+1);
    for(int i = 1;i<=n;++i)
        sum[i] = sum[i-1]+arr[i];
    int l = 0,r = 1e9,mid;
    while(l<r){
        mid = l+(r-l)/2;
        if(ok(mid)) r = mid;
        else l = mid+1;
    }
    printf("%d\n",r);

    return 0;
}
