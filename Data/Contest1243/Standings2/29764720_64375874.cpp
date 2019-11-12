#include<bits/stdc++.h>
using namespace std;
#define int long long
#define forinc(i,a,b) for(int i=a;i<=b;++i)
#define fordec(i,a,b) for(int i=a;i>=b;--i)
#define forv(i,x) for(auto &i:x)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int l,int r)
{
    return l+rng()%(r-l+1);
}
#define in ({int x=0;int c=getchar(),n=0;for(;!isdigit(c);c=getchar()) n=(c=='-');for(;isdigit(c);c=getchar()) x=x*10+c-'0';n?-x:x;})
#define pii pair<int,int>
#define fi first
#define se second
#define batbit(i,x) (x|(1ll<<i))
#define getbit(i,x) ((x>>i)&1)

const int mn=1001;
int n,a[mn];

bool check(int x)
{
    int cnt=0;
    forinc(i,1,n) if(a[i]>=x) cnt++;
    return (cnt>=x);
}

main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        forinc(i,1,n) cin >> a[i];
        sort(a+1,a+n+1);
        int l=1,r=1001,res;
        while(l<=r)
        {
            int m=(l+r)/2;
            if(check(m))
            {
                res=m;
                l=m+1;
            }
            else r=m-1;
        }
        cout << res << "\n";
    }
}
