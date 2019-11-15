#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const long double pi = acos(-1);
const double PI = acos(-1.);

#define MOD 1000000007

const int N = 1e5 + 5;
const int K = 2e2 + 2;
const int Ai = 1e6 + 6;
const int LOGN = 30;

int main() {
    ios_base::sync_with_stdio(false);

    int T; cin >> T;

    while(T--) {
        int n; cin >> n;
        string s, t; cin >> s >> t;

        map<char, int> cnt;

        for(auto x : s)
            cnt[x]++;
        for(auto x : t)
            cnt[x]++;

        bool b = true;
        for(auto x : cnt)
            if(x.second & 1)
                b = false;

        if(!b) {
            cout << "No\n";
            continue;
        }

        bool no = false;
        vector<pii> ve;
        for(int i = 0; i < n; i++) {
            if(s[i] != t[i]) {
                bool b = false;
                for(int j = 0; j < n; j++) {
                    if(i == j) continue;
                    if(b) break;

                    if(s[j] != t[j] && s[i] == s[j]) {
                        ve.push_back(pii(j, i));
                        swap(s[j], t[i]);
                        b = true;
                    }
                }

                for(int j = 0; j < n; j++) {
                    if(i == j) continue;
                    if(b) break;

                    if(s[j] != t[j] && s[i] == t[j]) {
                        ve.push_back(pii(j, j));
                        ve.push_back(pii(j, i));

                        swap(s[j], t[j]);
                        swap(s[j], t[i]);
                        b = true;
                    }
                }

                if(!b)
                    no = true;
            }
        }

        if(no || s != t)
            cout << "No\n";
        else {
            cout << "Yes\n";

            cout << ve.size() << "\n";

            for(auto x : ve)
                cout << x.first + 1 << " " << x.second + 1 << "\n";
        }
    }

    return 0;
}

