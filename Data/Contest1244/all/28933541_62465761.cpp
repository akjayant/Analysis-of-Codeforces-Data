#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mit map<int,int>::iterator
#define sit set<int>::iterator
#define itrm(g,x) for(mit g=x.begin();g!=x.end();g++)
#define itrs(g,x) for(sit g=x.begin();g!=x.end();g++)
#define ltype int
#define rep(i,j,k) for(ltype(i)=(j);(i)<=(k);(i)++)
#define rap(i,j,k) for(ltype(i)=(j);(i)<(k);(i)++)
#define per(i,j,k) for(ltype(i)=(j);(i)>=(k);(i)--)
#define pii pair<int,int>
#define fi first
#define se second
#define mpr make_pair
#define pb push_back
#define fastio ios::sync_with_stdio(false)
const int inf=0x3f3f3f3f,mod=1000000007;
const double pi=3.1415926535897932,eps=1e-6;
int T,a,b,c,d,k;
void solve(){
    scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
    int x=(a+c-1)/c,y=(b+d-1)/d;
    if(x+y>k) printf("-1\n");
    else printf("%d %d\n",x,y);
}
int main()
{
    scanf("%d",&T);
    while(T--) solve();
    return 0;
}