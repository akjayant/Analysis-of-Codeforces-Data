#include <bits/stdc++.h>

using namespace std;

const int N = 1e3+7;

int t, n;
string s;

int main()
{
    cin >> t;
    while (t--) {
        cin >> n >> s;
        int res = -1;
        for (int i = 0; i < (int)s.length(); ++i) {
            if (s[i] == '0') continue;
            res = max(res, max(i+1, (int)s.length()-i));
        }
        cout << (res == -1 ? n : res*2) << endl;
    }
    return 0;
}
