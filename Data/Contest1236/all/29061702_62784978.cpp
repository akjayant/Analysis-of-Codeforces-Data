#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<
 
typedef long long ll;
typedef long double ld;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t, a, b, c;
    cin >> t;
    while (t--) {
        cin >> a >> b >> c;
        int sol = 0;
        for (int i = 0; i <= min(a, b/2); i++) {
            int j = min(b - 2 * i, c/2);
            sol = max(sol, i + j);
        }
        cout << 3 * sol << endl;
    }


    return 0;
}

