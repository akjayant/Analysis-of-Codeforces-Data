#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define pb push_back
#define pf push_front
#define ft first
#define sc second
using namespace std;
const ll maxn = 150000;
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll n, k;
    cin >> n >> k;
    vector <ll> mas(n, 0);
    for (int d = 0; d < n; d++) {
        cin >> mas[d];
    }
    sort(mas.begin(), mas.end());
    deque<pair<ll, ll> > dq;
    for (int d = 0; d < n; d++) {
        ll cnt = 1;
        while (d < n - 1 && mas[d] == mas[d + 1]) {
            d++;
            cnt++;
        }
        dq.pb({mas[d], cnt});
    }
    while (k > 0 && dq.size() > 1) {
//        for (pair<ll, ll> u : dq) {
//            cout << u.ft << " " << u.sc << "\n";
//        }
//        cout << "\n";
        if (dq.front().sc <= dq.back().sc) {
            ll dif = dq[1].ft - dq[0].ft;
            if (k >= dif * dq[0].sc) {
                k -= dif * dq[0].sc;
                dq[1].sc += dq[0].sc;
                dq.pop_front();
            } else {
                ll k1 = k / dq[0].sc;
                dq[0].ft += k1;
                k = 0;
            }
        } else {
            ll sz = dq.size() - 1;
            ll dif = dq[sz].ft - dq[sz - 1].ft;
            if (k >= dif * dq[sz].sc) {
                k -= dif * dq[sz].sc;
                dq[sz - 1].sc += dq[sz].sc;
                dq.pop_back();
            } else {
                ll k1 = k / dq[sz].sc;
                dq[sz].ft -= k1;
                k = 0;
            }
        }
    }
    cout << dq.back().ft - dq.front().ft;
}
