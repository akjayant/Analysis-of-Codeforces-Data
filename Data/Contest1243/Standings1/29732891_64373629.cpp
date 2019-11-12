#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<vvvi> vvvvi;
typedef tuple<ll, ll, ll> iii;
typedef vector<iii> viii;
typedef pair<double, iii> diii;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vi V(n);
        for (int i = 0; i < n; ++i) cin >> V[i];
        sort(V.begin(), V.end(), greater<int>());
        int mx = 1;
        for (int i = 0; i < n; ++i) {
            if (V[i] < i+1) break;
            mx = max(mx, i+1);
        }
        cout << mx << "\n";
    }
    return 0;
}