#include<bits/stdc++.h>

#define ll long long
#define double long double
#define f(i, a, b) for(ll i=(a);i<=(b);++i)
#define rf(i, a, b) for(ll i=(a);i>=(b);--i)
#define Cl(a) memset(a,0,sizeof(a))
#define Cln(a) memset(a,0xff,sizeof(a))
#define cp(a, b) memcpy(a,b,sizeof(b))
#define sz(a) ((ll)((a).size()))
#define pb emplace_back
#define sqr(x) ((x)*(x))
#define all(a) (a).begin(),(a).end()
#define mpr make_pair
#define x first
#define y second
#define Debug(a) cout<<"---"<<a<<"---"<<endl;
#define endl '\n'
#define LL long long
using namespace std;

const ll N = 2e5, M = 10 + 5;
ll n;
long long p[4][N];
ll du[N];
vector<ll> e[N];
ll A[M][N];
long long Cost[M];

inline void dfs(ll ty, ll a, ll b, ll x, ll y) {
    if (sz(e[b]) == 1) return;
    ll c = (e[b][0] == a) ? e[b][1] : e[b][0];
    for (ll i = 0; i < 3; i++) {
        if (i == x || i == y) continue;
        A[ty][c] = i;
        Cost[ty] += p[i][c];
        dfs(ty, b, c, y, i);
        break;
    }
}

int main() {
    ll a, b, s;
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    f(i, 1, n)cin >> p[0][i];
    f(i, 1, n) cin >> p[1][i];
    f(i, 1, n)cin >> p[2][i];
    f(i, 0, n - 2) {
        cin >> a >> b;
        du[a]++;
        du[b]++;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    f(i, 1, n) {
        if (du[i] >= 3) {
            cout << -1 << endl;
            return 0;
        }
    }
    f(i, 1, n) {
        if (du[i] == 1) {
            s = i;
            break;
        }
    }
    ll st = s, tt = e[st][0];
    for (ll i = 0; i < 3; i++) {
        for (ll j = 0; j < 3; j++) {
            if (i == j) continue;
            Cost[i * 3 + j] = p[i][st] + p[j][tt];
            A[i * 3 + j][st] = i;
            A[i * 3 + j][tt] = j;
            dfs(i * 3 + j, st, tt, i, j);
        }
    }
    ll tsb = 0;
    long long ans = (ll) 1 << 60;
    for (ll i = 0; i < 3; i++) {
        for (ll j = 0; j < 3; j++) {
            if (i == j) continue;
            if (ans > Cost[i * 3 + j]) {
                ans = Cost[i * 3 + j];
                tsb = i * 3 + j;
            }
        }
    }
    cout << ans << endl;
    for (ll i = 1; i <= n; i++) {
        cout << A[tsb][i] + 1;
        if (i == n)cout << endl;
        else cout << ' ';
    }
    return 0;
}
