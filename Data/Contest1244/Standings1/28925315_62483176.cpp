


#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

const int MaxN = 100000 + 5;

int n, m;
long long lim;
int h[MaxN];
vector<long long> t, s;

int main() {
    cin >> n >> lim;
    for (int k = 0; k < n; ++ k)
        scanf("%d", h + k);
    sort(h, h + n);
    
    s.clear(); t.clear();
    s.push_back(h[0]);
    t.push_back(1);
    m = 1;
    for (int k = 1; k < n; ++ k) {
        if (h[k] == s[m - 1]) ++ t[m - 1];
        else {
            s.push_back(h[k]);
            t.push_back(1);
            ++ m;
        }
    }
    
    int l = 0, r = m - 1;
    while (l < r && (lim >= t[l] || lim >= t[r])) {
        if (t[l] <= t[r]) {
            long long det = min(lim / t[l], s[l + 1] - s[l]);
            lim -= det * t[l];
            s[l] += det;
            if (s[l] == s[l + 1]) {
                t[l + 1] += t[l];
                ++ l;
            }
        }
        else {
            long long det = min(lim / t[r], s[r] - s[r - 1]);
            lim -= det * t[r];
            s[r] -= det;
            if (s[r] == s[r - 1]) {
                t[r - 1] += t[r];
                -- r;
            }            
        }
    }
    cout << s[r] - s[l] << endl;
    
    return 0;
}
