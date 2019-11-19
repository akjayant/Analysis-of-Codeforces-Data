#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define vi vector<int>
#define vll vector<ll>
#define si set<int>
#define sll set<ll>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define fo(i,a,b) for(int i=a;i<b;i++)
#define fo_(i,a,b) for(int i=a;i>b;i--)
#define M(a) memset(a,0,sizeof a)
#define M_(a) memset(a ,-1,sizeof a)
#define deb(x)  cerr << #x << " = " << x << endl
#define pb push_back
#define F first
#define S second
#define OK order_of_key
#define FO find_by_order
#define PI 3.14159265
#define nmax 100100
const ll inf = std::numeric_limits<ll>::max();
const int infint = std::numeric_limits<int>::max();
const ll mod = 1e9+7;
using namespace __gnu_pbds;
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


vll divs(ll n){
    vll out;
    fo(i,1,sqrt(n)){
        if(n%i == 0){
            out.pb(i);
            out.pb(n/i);
        }
    }
    if(sqrt(n)*sqrt(n) == n) out.pb((ld)sqrt(n)+0.001);
    sort(out.begin(),out.end());
    return out;
}


int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n;
    cin >> n;
    if(n==1) return cout << 1,0;
    vll ans = divs(n);
    ll cc = n;
    while(cc%ans[1] == 0) cc/=ans[1];
    if(cc == 1) cout << ans[1];
    else cout << 1;

    return 0;
}

