#include <iostream>
#include <cmath>
#include <random>
#include <cassert>
#include <iomanip>
#include <set>
#include <map>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <unordered_map>
#include <unordered_set>
#define int long long
using namespace std;


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, r, p, s;
        cin >> n >> r >> p >> s;
        string str;
        cin >> str;
        int R = 0, P = 0, S = 0;
        for (char c: str) {
            if (c == 'R') R++;
            if (c == 'P') P++;
            if (c == 'S') S++;
        }
        int wins = min(r, S) + min(p, R) + min(s, P);
        if (wins >= (n + 1) / 2) {
            cout << "YES" << endl;
            string ans = str;
            string used = ans;
            for (int i = 0; i < ans.length(); i++) {
                used[i] = 'F';
                if (ans[i] == 'S' && r) {
                    ans[i] = 'R';
                    r--;
                    used[i] = 'T';
                }
                else if (ans[i] == 'R' && p) {
                    ans[i] = 'P';
                    p--;
                    used[i] = 'T';
                }
                else if (ans[i] == 'P' && s) {
                    ans[i] = 'S';
                    s--;
                    used[i] = 'T';
                }
            }
            for (int i  =0; i < ans.length(); i++) {
                if (used[i] == 'F') {
                    if (r) {
                        ans[i] = 'R';
                        r--;
                    }
                    else if (s) {
                        ans[i] = 'S';
                        s--;
                    }
                    else if (p) {
                        ans[i] = 'P';
                        p--;
                    }
                }
            }
            cout << ans << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}