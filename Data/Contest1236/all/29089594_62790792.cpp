#include <bits/stdc++.h>
using namespace std;
#define FOR(i,x,y) for(int i=(int)(x);i<(int)(y);++i)
#define FORE(i,x,y) for(int i=(int)(x);i<=(int)(y);++i)
#define FORD(i,x,y) for(int i=(int)(x);i>=(int)(y);--i)
#define PB push_back
#define MP make_pair
#define ST first
#define ND second
typedef long long ll;
typedef pair<int,int> pii;
const int INF=2e9;
const ll MOD=1e9+7;
const int MAXN=1e6+6;

ll ans=0;
ll n,m,k,q;
ll pot(ll pod,ll wyk){
    if(wyk==0)return 1;
    ll x=pot(pod,wyk/2);
    x*=x;
    x%=MOD;
    if(wyk%2)return (x*pod)%MOD;
    else return x;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    ll dla1=pot(2,m)-1;
    cout<<pot(dla1,n);
    return 0;
}
