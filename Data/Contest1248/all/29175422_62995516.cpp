#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define print(x, text) cout << text << " = " << x << endl;
#define printv(x, text) cout << text << " = "; for (auto e : x) cout << e << ' '; cout << endl;

typedef long long ll;

int n;
string s;

int f(int l, int r) {
    swap(s[l], s[r]);

    int ans = 0;
    int bal = 0;
    int mn = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') bal++;
        else bal--;
        if (bal < mn) mn = bal, ans = 0;
        if (bal == mn) ans++;
    }

    swap(s[l], s[r]);
    return ans * (bal == 0);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> s;

    int ans = 0;
    int L = 0, R = 0;
    for (int l = 0; l < n; ++l) {
        for (int r = l; r < n; ++r) {
            int tmp = f(l, r);
            if (tmp > ans) {
                ans = tmp, L = l, R = r;
            }
        }
    }

    cout << ans << endl << L + 1 << ' ' << R + 1;
}

/*
12
)(()(()())()

12
()()(()())()

 12
(())()()(())
*/
