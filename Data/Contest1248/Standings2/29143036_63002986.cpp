#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>
#include <queue>
using namespace std;

typedef long long int64;

const int INF = 0x3f3f3f3f;
const int MAXN = 1010;

char s[MAXN];
int sum[MAXN];

int main() {
    int n;
    cin >> n;
    scanf("%s", s + 1);
    for (int i = 1; i <= n; i++) {
        s[n + i] = s[i];
    }
    int ans = 0, ansl = 1, ansr = 1;
    for (int l = 1; l <= n; l++) {
        for (int r = l; r <= n; r++) {
            swap(s[l], s[r]);
            swap(s[l + n], s[r + n]);

            memset(sum, 0, sizeof sum);
            int cur = 0;
            deque<pair<int, int>> q;
            for (int i = 1; i < n * 2; i++) {
                sum[i] = sum[i - 1] + ((s[i] == '(') ? 1 : -1);
                while (!q.empty() && q.front().second < i - n) q.pop_front();
                if (i >= n && q.front().first >= sum[i]) {
                    if (sum[i] == sum[i - n]) cur++;
                }
                while (!q.empty() && q.back().first >= sum[i]) q.pop_back();
                q.push_back(make_pair(sum[i], i));
            }
            if (cur > ans) {
                ans = cur;
                ansl = l;
                ansr = r;
            }

            swap(s[l], s[r]);
            swap(s[l + n], s[r + n]);
        }
    }
    cout << ans << endl;
    cout << ansl << ' ' << ansr << endl;
}