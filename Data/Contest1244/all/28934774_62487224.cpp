#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;

signed main()
{
    //freopen("IN.txt", "r", stdin);
    //freopen("OUT.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    ll k; cin >> n >> k;

    map<int,int> M;
    set<int> s;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        M[x]++;
        s.insert(x);
    }

    ll steps = 0;

    while(1) {
        int x1 = *(s.begin());
        int cnt1 = M[x1];
        int x2 = *(s.rbegin());
        int cnt2 = M[x2];
        if(x1 == x2) {
            break;
        }
        if(cnt1 < cnt2) {
            s.erase(s.find(x1));
            int y = *(s.begin());
            ll R = 1LL * (y - x1) * cnt1;
            if(steps + R >= k) {
                x1 += (k - steps) / cnt1;
                cout << x2 - x1 << "\n";
                return 0;
            }
            steps += R;
            M[y] += cnt1;
        }
        else {
            s.erase(s.find(x2));
            int y = *(s.rbegin());
            ll R = 1LL * (x2 - y) * cnt2;
            if(steps + R >= k) {
                x2 -= (k - steps) / cnt2;
                cout << x2 - x1 << "\n";
                return 0;
            }
            steps += R;
            M[y] += cnt2;
        }
    }

    cout << "0\n";

    return 0;
}
