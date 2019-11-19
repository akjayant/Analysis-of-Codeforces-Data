#include <bits\stdc++.h>

#define sc second
#define fr first
#define mk make_pair
#define pb push_back
#define int long long

using namespace std;

const int N = (1e6 + 5);
const int inf = (1e9 + 7);

int n,k;
int a[N];
int p[N];
int l,r;

bool check (int x) {
    for (int i = 1; i <= n; i ++) {
        int cur = a[i] + x;
        int need = i * a[i] - p[i];

        int lo = i,hi = n;

        while (hi - lo > 1) {
            int mid = (hi + lo) >> 1;
            if (a[mid] >= cur) hi = mid;
            else lo = mid;
        }
        if (a[lo] >= cur) hi = lo;

        need += abs(cur * (n - hi + 1) - (p[n] - p[hi - 1]));

        if (need <= k) return true;
    }

    for (int i = n; i >= 1; i --) {
        int cur = a[i] - x;

        int need = abs(((n - i + 1) * a[i]) - (p[n] - p[i - 1]));
        int lo = 1,hi = i;

        while (hi - lo > 1) {
            int mid = (hi + lo) >> 1;
            if (a[mid] <= cur) lo = mid;
            else hi = mid;
        }
        if (a[hi] <= cur) lo = hi;

        need += abs(cur * lo - p[lo]);

        if (need <= k) return true;
    }
    return false;
}
main () {
    cin >> n >> k;

    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    sort (a + 1,a + n + 1);

    for (int i = 1; i <= n; i ++) {
        p[i] += p[i - 1] + a[i];
    }
    int l = 0,r = a[n] - a[1];

    while (r - l > 1) {
        int m = (r + l) >> 1;
        if (check(m)) r = m;
        else l = m;
    }
    if (check(l)) r = l;
    cout << r << endl;
}
