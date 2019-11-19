#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

#define p_ary(ary,a,b) do { cout << "["; for (int count = (a);count < (b);++count) cout << ary[count] << ((b)-1 == count ? "" : ", "); cout << "]\n"; } while(0)
#define p_map(map,it) do {cout << "{";for (auto (it) = map.begin();;++(it)) {if ((it) == map.end()) {cout << "}\n";break;}else cout << "" << (it)->first << "=>" << (it)->second << ", ";}}while(0)

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0;i < n;++i) cin >> a[i];
    sort(a.begin(),a.end());
    ll x = 0,y = 0;
    for (int i = 0;i < n/2;++i) x += a[i];
    for (int i = n/2;i < n;++i) y += a[i];
    cout << x*x+y*y << endl;
    return 0;
}