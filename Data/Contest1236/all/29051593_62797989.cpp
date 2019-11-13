#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define frac pair<ll, ll>
#define t_trials for (cin >> _; _; _--)
#define rep(i, l, r) for (ll i = (l); i < (r); ++i)
#define N 200005
const ll inf = 1e9 + 7;
ll arr[N];
ll n, m, k, t, t1, t2, t3, t4, t5, t6, _;
string s;
vector<ll> ans[400];
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    rep(i, 0, n * n)
    {
        rep(j,0,n){
            ans[j].push_back(++i);
        }
        rep(j,0,n){
            ans[n-1-j].push_back(++i);
        }
        i--;
    }
    rep(i,0,n){
        rep(j,0,n){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}