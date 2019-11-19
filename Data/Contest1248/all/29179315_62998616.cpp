#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <map>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <iomanip>
#include <queue>

using namespace std;


const int inf = (int) 1e9;
const int mod = 1e9 + 7;
const int max_n = 500;

#define ll long long
#define ld long double
#define all(x) x.begin(), x.end()

int prefix[max_n];
int min_prefix[max_n];
int sufix[max_n];
bool bad[max_n];


int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int best = 0;
    int best_l = 0;
    int best_r = 0;
    for (int l = 0; l < n; ++l) {
        for (int r = l; r < n; ++r) {
            string t = s;
            fill(bad, bad + n, false);
            swap(t[l], t[r]);
            bool good = false;
            int cnt = 0;
            int mn = 0;
            for (int i = 0; i < t.size(); ++i) {
                if (t[i] == '(') {
                    cnt++;
                } else {
                    cnt--;
                }
                mn = min(mn, cnt);
                min_prefix[i] = mn;
                prefix[i] = cnt;
            }
            good = cnt == 0 && mn >= 0;
            cnt = 0;
            bool b = false;
            mn = 0;
            for (int i = t.size() - 1; i >= 0; --i) {
                if (t[i] == '(') {
                    cnt++;
                    mn++;
                } else {
                    cnt--;
                    mn--;
                }
                mn = min(cnt, mn);
                mn = min(mn, 0);
                sufix[i] = cnt;
                bad[i] = mn < 0;
            }
            int ans = 0;
            for (int i = 0; i < n - 1; ++i) {
                if (prefix[i] + sufix[i + 1] == 0 && !bad[i + 1] && sufix[i + 1] + min_prefix[i] >= 0) {
                    ans++;
                }
            }
            if(good) ans++;
            if (ans > best) {
                best = ans;
                best_l = l;
                best_r = r;
            }
        }
    }
    cout << best << "\n" << best_l + 1 << " " << best_r + 1;
    return 0;
}