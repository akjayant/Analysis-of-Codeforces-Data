#include <bits/stdc++.h>
using namespace std;
#define int long long
int hmt() {int x=0;int c=getchar(),n=0;for(;!isdigit(c);c=getchar()) n=(c=='-');for(;isdigit(c);c=getchar()) x=x*10+c-'0';return n?-x:x;}
#define in hmt()
#define forinc(i,a,b) for(int i=a;i<=b;i++)
#define fordec(i,a,b) for(int i=a;i>=b;i--)
#define fi first
#define se second
#define getbit(i,x) ((x>>i)&1ll)
#define ii pair<int,int>

const int maxn=1e5+5;
int t,ret=1;
int n,b[maxn];

main()
{
    cin>>t;
    while(t--)
    {
        ret=1;
    cin>>n;
    forinc(i,1,n) cin>>b[i];
    sort(b+1,b+n+1);
    forinc(i,1,n) ret=max(ret,min(b[i],n-i+1));
    cout<<ret<<"\n";
    }
}
