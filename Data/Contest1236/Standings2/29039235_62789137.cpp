#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <unordered_map>
#define fir first
#define se second
#define ll long long
#define pb push_back
#define mp make_pair
#define ull unsigned long long
#define cl(a,b) memset(a,b,sizeof(a))
#define quickio(a) ios::sync_with_stdio(a)
#define datatest() freopen("data.in","r",stdin)
#define makeans() freopen("data.out","w",stdout)
#define makedata() freopen("data.in","w",stdout)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pdd pair<double,double>
using namespace std;
const int maxn=1e6+10;
const int maxm=1e6+10;
const int inf=0x3f3f3f3f;
const ll mod=1e9+7;
const int maxblock=sqrt(maxn)+10;
const double eps=1e-7;
const ll INF=1e16;
ll qpow(ll a,ll b,ll p){
    ll res=1;
    while (b){
        if (b&1) res=res*a%p;
        b>>=1;
        a=a*a%p;
    }
    return res;
}

int main(){
    ll n,m;
    cin>>n>>m;
    ll res=qpow(((qpow(2,m,mod)-1)%mod+mod)%mod,n,mod);
    cout<<res<<endl;
    return 0;
}