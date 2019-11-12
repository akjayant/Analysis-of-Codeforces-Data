#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> ii;

const ll N = 1e6 + 5;
const ll INF = 1e9 + 7;

int T, n, k;
string s, t;

void inp() {
    cin >> T;
}
void solve() {
    while (T--) {
        cin >> n >> s >> t;
        vector <ii> V; V.clear();
        for (int i = 0; i < n; i++)
            if (s[i] != t[i]) {
                for (ll j = i + 1; j < n; j++)
                    if (t[i] == t[j]) {
                        V.push_back(ii(i, j));
                        swap(s[i], t[j]);
                        break;
                    }
                    else if (s[j] == t[i]){
                        V.push_back(ii(i, i));
                        swap(s[i], t[i]);
                        V.push_back(ii(j, i));
                        swap(s[j], t[i]);
                        break;
                    }
                    else if (s[i] == t[j]){
                        V.push_back(ii(i, i));
                        swap(s[i], t[i]);
                        V.push_back(ii(i, j));
                        swap(s[i], t[j]);
                        break;
                    }
            }
        if (s == t)
        {
            cout << "Yes\n";
            cout << V.size() << "\n";
            for (int i = 0; i < V.size(); i++)
                cout<< V[i].first + 1 << " " << V[i].second + 1 << "\n";
        }
        else
            cout << "No\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   // freopen("test.INP", "r", stdin);
   // freopen("test.OUT", "w", stdout);
    inp();
    solve();
}
