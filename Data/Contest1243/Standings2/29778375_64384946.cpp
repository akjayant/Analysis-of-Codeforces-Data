#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

#define p_ary(ary,a,b) do { cout << "["; for (int count = (a);count < (b);++count) cout << ary[count] << ((b)-1 == count ? "" : ", "); cout << "]\n"; } while(0)
#define p_map(map,it) do {cout << "{";for (auto (it) = map.begin();;++(it)) {if ((it) == map.end()) {cout << "}\n";break;}else cout << "" << (it)->first << "=>" << (it)->second << ", ";}}while(0)

ll gcd(ll a,ll b) {
    while (b) {
        a %= b;
        swap(a,b);
    }
    return a;
}

int main() {
    ll n;
    cin >> n;
    ll g = n;
    vector<ll> a;
    for (ll i = 2;i*i <= n;++i) if (n%i == 0) {
        a.push_back(i);
        while (n%i == 0) n /= i;
    }
    if (n > 1) a.push_back(n);
    for (ll i : a) g = gcd(g,i);
    cout << g << endl;
}