#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<ll, pll> tpl;
const int MAXN = 1e5 + 10;

int N;
ll X[MAXN], Y[MAXN];
ll C[MAXN], K[MAXN];
vector<tpl> V;
int P[MAXN];
vector<ll> vv;
vector<pll> ee;

ll find(ll here){
    if(here == P[here]) return here;
    return P[here] = find(P[here]);
}

int main(){
    scanf("%d", &N);
    for(int i = 1 ; i <= N ; i++) scanf("%lld%lld", X + i, Y + i);

    for(int i = 1 ; i <= N ; i++) scanf("%lld", C + i);
    for(int i = 1 ; i <= N ; i++) scanf("%lld", K + i);

    int sink = N + 1;
    for(int i = 1 ; i <= N ; i++) V.push_back(tpl(C[i], pll(i, sink)));

    for(int i = 1 ; i <= N ; i++){
        for(int j = i + 1; j <= N ; j++) {
            ll ccc = (K[i] + K[j]) * (abs(X[i] - X[j]) + abs(Y[i] - Y[j]));
            V.push_back(tpl(ccc, pll(i, j)));
        }
    }

    sort(V.begin(), V.end());

    for(int i = 1 ; i <= N + 1 ; i++) P[i] = i;

    ll ans = 0;
    for(auto val : V){
        ll ccc = val.first;
        ll n1 = val.second.first;
        ll n2 = val.second.second;

        ll p1 = find(n1);
        ll p2 = find(n2);

        if(p1 == p2) continue;
        ans += ccc;
        P[p1] = p2;

        if(n2 == sink) vv.push_back(n1);
        else ee.push_back(pll(n1, n2));
    }

    printf("%lld\n", ans);
    printf("%lu\n", vv.size());
    for(auto val : vv) printf("%lld ", val);
    printf("\n");
    printf("%lu\n", ee.size());
    for(auto val : ee) printf("%lld %lld\n", val.first, val.second);

}