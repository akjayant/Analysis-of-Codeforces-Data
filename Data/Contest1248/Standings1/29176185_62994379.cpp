#include <bits/stdc++.h>

#define fi first
#define se second
#define m_p make_pair
#define endl '\n'
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)

using namespace std;

typedef long long ll;

const int MAXN = 1123456;
const int MAXINT = 2147483098;
const ll MAXLL = 9223372036854775258LL;
const ll MOD = 1e9 + 7;

string s;
int n, k1 = 0, k2 = 0, L = 0, R = 0, answer = 0;

void makeSomeXuinya(int minBalance, int l, int r) {
    int balance = 0;
    int ans = 0;
    for (int k = 0; k < n; ++k) {
        if (k == 0) {
            if (minBalance >= 0) ans++;
        }else {
            if (s[n - k] == ')') minBalance--;
            else minBalance++;
            if (minBalance >= 0) ans++;
        }

    }
   // cout << l << " " << r << " " << ans << endl;
    if (ans >= answer) {
        answer = ans;
        L = l, R = r;
    }
}

int main()
{
    fast_io;


    cin >> n;
    cin >> s;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') k1++;
        else k2++;
    }
    if (k1 != k2) {
        cout << 0 << endl;
        cout << 1 << " " << 1 << endl;
        return 0;
    }

    for (int l = 0; l < n; ++l){

        for (int r = l; r < n; ++r) if (s[l] != s[r] || (l == r)){
            swap(s[l], s[r]);

            int min_balance = MAXINT, b = 0;
            for (int j = 0; j < n; ++j) {
            if (s[j] == '(') b++;
            else {
                b--;
            }
            min_balance = min(min_balance, b);
            }
            makeSomeXuinya(min_balance, l, r);

            swap(s[l], s[r]);
        }
    }

    cout << answer << endl;
    cout << L + 1<< " " << R + 1<< endl;

    return 0;
}
