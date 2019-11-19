#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for(int i = 1; i <= n; ++i) {
        ll a, b, c, d, e;
        cin >> a >> b >> c >> d >> e;
        ll pen = (a / c) + (a % c != 0 ? 1 : 0);
        ll pencil = (b / d) + (b % d != 0 ? 1 : 0);
        if (pen + pencil > e) cout << -1 << endl;
        else cout << pen << " " << pencil << endl;
    }
}