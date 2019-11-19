#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define boost ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define pii pair<int,int>
using namespace std;
int a, b, c, d, k, q;
int32_t main()
{   //srand(chrono::steady_clock::now().time_since_epoch().count());
    boost;
    cin >> q;
    while(q--) {
        cin >> a >> b >> c >> d >> k;
        int olowki = b / d;
        if(b % d) olowki++;
        int dlugopisy = a / c;
        if(a % c) dlugopisy++;
        if(olowki + dlugopisy <= k) {
            cout << dlugopisy << " " << olowki << "\n";
        } else cout << "-1\n";
    }
}
