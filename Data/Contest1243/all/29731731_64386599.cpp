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

        map<char, int> cnt, cnt1, cnt2;

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

        for(auto x : s)
            cnt1[x]++;
        for(auto x : t)
            cnt2[x]++;

        if(s == t) {
            bool b = false;
            for(auto x : cnt1) {
                if(cnt2.count(x.first))
                    b = true;
            }

            if(b)
                cout << "Yes\n";
            else
                cout << "No\n";
            continue;
        }

        int last = -1;
        for(int i = 0; i < n; i++) {
            if(s[i] != t[i]) {
                last = i;
                break;
            }
        }

        int last2 = -1;
        for(int i = 0; i < n; i++) {
            if(s[i] != t[i] && i != last) {
                last2 = i;
                break;
            }
        }

        if(last == -1 || last2 == -1) {
            cout << "No\n";
            continue;
        }

        swap(s[last], t[last2]);

        if(s != t)
            cout << "No\n";
        else {
            cout << "Yes\n";
        }
    }

    return 0;
}

