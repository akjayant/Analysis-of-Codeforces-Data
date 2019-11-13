#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<
 
typedef long long ll;
typedef long double ld;
  
int to_int(char c) {
    if (c == 'R') return 0;
    if (c == 'P') return 1;
    return 2;
}

int beats(char c) {
    if (c == 'R') return 'P';
    if (c == 'P') return 'S';
    return 'R';
}

int to_char(int i) {
    if (i == 0) return 'R';
    if (i == 1) return 'P';
    return 'S';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, a[3];
        string s;
        cin >> n >> a[0] >> a[1] >> a[2] >> s;
        string sol(n, '0');
        int won = 0;
        for (int i = 0; i < n; i++) {
            int x = to_int(beats(s[i]));
            if (a[x] > 0) {
                a[x]--;
                sol[i] = beats(s[i]);
                won++;
            }
        }
        for (int i = 0; i < n; i++) {
            if (sol[i] != '0') continue;
            for (int j : {0, 1, 2}) {
                if (a[j] > 0) {
                    sol[i] = to_char(j);
                    a[j]--;
                    break;
                }
            }
        }
        if (won >= (n + 1)/2) {
            cout << "YES\n" << sol << "\n";
        } else {
            cout << "NO\n";
        }
    }


    return 0;
}

