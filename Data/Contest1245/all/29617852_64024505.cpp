# include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, a, b, c;
        string s, ans;
        cin >> n >> a >> b >> c;
        cin >> s;
        for(int i = 0; i< n; i++)
            ans += '0';
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'R') {
                cnt += (b > 0);
                if (b > 0)
                    ans[i] = 'P',
                    b --;
            }
            if (s[i] == 'P') {
                cnt += (c > 0);
                if (c > 0)
                    ans[i] = 'S',
                    c--;
            }
            if (s[i] == 'S') {
                cnt += (a > 0);
                if (a > 0)
                    ans[i] = 'R',
                    a--;
            }
        }
        if (cnt >= (n + 1) / 2) {
            for (int i = 0; i < n;i++) {
                if (ans[i] == '0') {
                    if (a > 0) {
                        ans[i] = 'R';
                        a --;
                    } else if (b > 0) {
                        ans[i] = 'P';
                        b --;
                    } else {
                        ans[i] = 'S';
                        c --;
                    }
                }
            }
            puts("YES");
            cout << ans << endl;
        }
        else
            puts("NO");

    }
}
