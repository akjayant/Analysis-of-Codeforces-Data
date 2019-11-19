#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());

ll INF = (ll) 1e20;
int iINF = (int) 1e20;
ll mod = (ll) 1e9 + 7;

ll c1[100001];
ll c2[100001];
ll c3[100001];

ll get(ll v, vector<vector<ll>> &nodes, ll a, ll b, ll c, vector<ll> &cols, ll now, ll p) {
    ll ans = 0;
    if (now % 3 == 0) {
        cols[v] = a;
        if (a == 1) {
            ans = c1[v];
        }
        if (a == 2) {
            ans = c2[v];
        }
        if (a == 3) {
            ans = c3[v];
        }
    }
    if (now % 3 == 1) {
        cols[v] = b;
        if (b == 1) {
            ans = c1[v];
        }
        if (b == 2) {
            ans = c2[v];
        }
        if (b == 3) {
            ans = c3[v];
        }
    }
    if (now % 3 == 2) {
        cols[v] = c;
        if (c == 1) {
            ans = c1[v];
        }
        if (c == 2) {
            ans = c2[v];
        }
        if (c == 3) {
            ans = c3[v];
        }
    }
    for (auto i : nodes[v]) {
        if (p != i) {
            ans += get(i, nodes, a, b, c, cols, now + 1, v);
        }
    }
    return ans;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, k;
    cin >> n >> k;
    set<pair<ll, ll>>
    st;
    map < ll, ll > mp;
    for (int i = 0; i < n; ++i) {
        ll a;
        cin >> a;
        mp[a]++;
    }
    for (auto i : mp) {
        st.insert(i);
    }
    while (true) {
        if ((*st.begin()).first == (*(st.rbegin())).first) {
            break;
        }
        pair<ll, ll>
        b = (*st.begin());
        pair<ll, ll>
        c = (*st.rbegin());
        if (b.second < c.second) {
            ll cost = b.second;
            ll can = b.first;
            auto kek = st.begin();
            ++kek;
            ll num = (*kek).first;
            can = num - can;
            if (can * cost <= k) {
                k -= can * cost;
                st.erase(st.begin());
                pair<ll, ll>
                nw = (*st.begin());
                st.erase(st.begin());
                nw.second += b.second;
                st.insert(nw);
            } else {
                ll number = k / cost;
                st.erase(st.begin());
                b.first += number;
                st.insert(b);
                k -= number * cost;
                if (number == 0)
                    break;
            }
        } else {
            ll cost = c.second;
            ll can = c.first;
            auto kek = st.end();
            --kek;
            --kek;
            ll num = (*kek).first;
            can = can - num;
            if (can * cost <= k) {
                k -= can * cost;
                auto mem = st.end();
                --mem;
                st.erase(mem);
                pair<ll, ll>
                nw = (*st.rbegin());
                auto lol = st.end();
                --lol;
                st.erase(lol);
                nw.second += c.second;
                st.insert(nw);
            } else {
                ll number = k / cost;
                auto mem = st.end();
                --mem;
                st.erase(mem);
                c.first -= number;
                st.insert(c);
                k -= number * cost;
                if (number == 0)
                    break;
            }
        }
    }
    cout << (*st.rbegin()).first - (*st.begin()).first;
}
