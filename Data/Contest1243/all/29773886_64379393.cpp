#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(int argc, char *argv[]) {
    int TC; cin >> TC;
    while (TC--) {
        int n;
        cin >> n;
        string s, t;
        cin >> s >> t;
        int dif_cnt = 0;
        for (int i=0;i<n;i++) {
            if (s[i] != t[i])
                dif_cnt++;
        }
        if (dif_cnt != 2) {
            cout << "No" << endl;
            continue;
        }
        int l = -1, r = -1;
        for (int i=0;i<n;i++) {
            if (s[i] != t[i]) {
                if (l == -1)
                    l = i;
                else
                    r = i;
            }
        }
        if (s[l] == s[r] && t[r] == t[l])
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

    return 0;
}