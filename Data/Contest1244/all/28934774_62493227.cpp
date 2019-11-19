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

    int n, k; cin >> n >> k;
    string s; cin >> s;
    int val[n];
    for(int i = 0; i < n; i++) {
        val[i] = (s[i] == 'B');
    }

    int nxt[n], prev[n];
    memset(nxt, -1, sizeof(nxt));
    memset(prev, -1, sizeof(prev));

    int last = -1;

    for(int i = n - 1; i >= 0; i--) {
        if(s[i] == s[(i + 1) % n]) {
            last = i;
        }
        nxt[i] = last;
    }

    for(int i = n - 1; i >= 0; i--) {
        if(nxt[i] == -1) {
            nxt[i] = nxt[0];
        }
        else {
            break;
        }
    }

    last = -1;

    for(int i = 0; i < n; i++) {
        if(s[i] == s[(i - 1 + n) % n]) {
            last = i;
        }
        prev[i] = last;
    }

    for(int i = 0; i < n; i++) {
        if(prev[i] == -1) {
            prev[i] = prev[n - 1];
        }
        else {
            break;
        }
    }

    if(nxt[0] == -1) {
        for(int i = 0; i < n; i++) {
            if(k % 2) {
                val[i] ^= 1;
            }
        }
        for(int i = 0; i < n; i++) {
            if(val[i]) {
                cout << "B";
            }
            else {
                cout << "W";
            }
        }
        return 0;
    }

    for(int i = 0; i < n; i++) {
        if(nxt[i] != i && prev[i] != i) {
            int d1, d2;
            if(nxt[i] < i) {
                d1 = n - (i - nxt[i]);
            }
            else {
                d1 = nxt[i] - i;
            }
            if(prev[i] > i) {
                d2 = n - (prev[i] - i);
            }
            else {
                d2 = i - prev[i];
            }
            if(min(d1, d2) > k) {
                if(k % 2) {
                    val[i] ^= 1;
                }
            }
            else {
                if(d1 < d2) {
                    val[i] = val[nxt[i]];
                }
                else {
                    val[i] = val[prev[i]];
                }
            }
        }
    }

    for(int i = 0; i < n; i++) {
        if(val[i]) {
            cout << "B";
        }
        else {
            cout << "W";
        }
    }
    cout << "\n";

    return 0;
}
