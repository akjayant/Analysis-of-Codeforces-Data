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
        string s, t;
        cin >> s >> t;
        if (s == t) cout << "YES\n";
        else {
            vi aux;
            for (int i = 0; i < n; ++i) {
                if (s[i] != t[i]) aux.push_back(i);
            }
            if (aux.size() == 2) swap(s[aux[0]], t[aux[1]]);
            if (s != t) cout << "NO\n";
            else cout << "YES\n";
        }
    }
    return 0;
}