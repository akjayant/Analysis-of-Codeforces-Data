#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define frac pair<ll,ll>
#define t_trials for (cin >>_;_;_--)
#define rep(i, l, r) for (ll i = (l); i < (r); ++i)
# define N 200005
const ll inf = 1e9+7;
ll mod = 1000000007;
ll arr[N];
ll n,m,k,t,t1,t2,t3,t4,t5,t6,_;
string s;

ll power(ll x, ll y, ll md){
    if(y==0){
        return 1;
    }
    ll temp = power(x,y/2,md);
    if(y&1){
        return (((temp*temp)%md)*x)%md;
    }
    return (temp*temp)%md;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    t = (power(2,m,mod)-1);
    t1 = power(t,n,mod);
    cout << t1 << endl;
    return 0;
}