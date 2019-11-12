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
        map<char, int> freq;
        for (int i = 0; i < n; ++i) freq[s[i]]++, freq[t[i]]++;
        bool flag = true;
        for (auto v : freq) {
            if (v.S%2) flag = false;
        }
        if (!flag) cout << "NO\n";
        else {
            cout << "YES\n";
            vii swaps;
            for (int i = 0; i < n; ++i) {
                if (s[i] != t[i]) {
                    bool swapped = false;
                    for (int j = i+1; j < n; ++j) {
                        if (s[j] == t[i]) {
                            swap(s[j], t[j]);
                            swaps.push_back({j+1, j+1});
                        }
                        if (t[j] == t[i]) {
                            swap(s[i], t[j]);
                            swaps.push_back({i+1, j+1});
                            break;
                        }
                    }
                }
            }
            cout << swaps.size() << "\n";
            for (int i = 0; i < swaps.size(); ++i) cout << swaps[i].F << " " << swaps[i].S << "\n";
        }
    }
    return 0;
}