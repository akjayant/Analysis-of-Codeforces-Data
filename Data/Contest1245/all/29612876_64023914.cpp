#include <bits/stdc++.h>
#define E 0.000000000001
using namespace std;
 
typedef long long ll;
typedef pair <ll, ll> pll;

const ll maxn = 2e3 + 1;
ll n;
ll g[maxn][maxn];
ll c[maxn];

ll m_dist(pll a, pll b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

set <pll> st;
pll answ[maxn];
bool used[maxn];

void step1() {
    cin >> n;
    vector <pll> inp(n);
    for(auto &i: inp) cin >> i.first >> i.second;
    ll k[n];
    for(ll i = 0; i < n; i++) {
        cin >> c[i];
        answ[i] = {c[i], -1};
        st.insert({c[i], i});
    }
    for(ll i = 0; i < n; i++) cin >> k[i];
    for(ll i = 0; i < n; i++) {
        for(ll j = i; j < n; j++) {
            g[i][j] = g[j][i] = (k[i] + k[j]) * m_dist(inp[i], inp[j]);
        }
    }
}


void dej() {
    
}

int main() {
    ios_base:: sync_with_stdio(false);
    step1();
    
    while(st.size()) {
        ll ind = (*st.begin()).second;
        st.erase(st.begin());
        for(ll i = 0; i < n; i++) {
            if(st.count({answ[i].first, i})) {
                if(answ[i].first > g[ind][i]) {
                    st.erase({answ[i].first, i});
                    answ[i] = {g[ind][i], ind};
                    st.insert({answ[i].first, i});
                }
            }
        }
    }
    
    ll cnt = 0;
    vector <ll> fire;
    set <pll> edge;
    for(ll i = 0; i < n; i++) {
        cnt += answ[i].first;
        if(answ[i].second == -1) fire.push_back(i);
        else {
            edge.insert({i, answ[i].second});
        }
    }
    cout << cnt << endl << fire.size() << endl;;
    for(auto i: fire) cout << i + 1 << ' '; cout << endl;
    cout << edge.size() << endl;
    for(auto i: edge) cout << i.first + 1 << ' ' << i.second + 1 << endl;;
}
 