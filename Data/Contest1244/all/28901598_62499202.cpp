#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define int long long
typedef pair<int, int> ii;

const int mod = 1e9 + 7;

const int inf = 1e9;

int add(int x, int y) {
    return (1ll * x + 1ll * y) % mod;
}

int del(int x, int y) {
    return ((1ll * x - 1ll * y) % mod + mod) % mod;
}

int mul(int x, int y) {
    return (1ll * x * 1ll * y) % mod;
}

const int N = 1e5 + 5;

int n, k, a[N], pref[N], suff[N];

bool check(int x) {
    int pter = 1;
    for(int i = 1; i <= n; i++) {
        while(pter <= n && a[pter] - a[i] <= x) pter++;
        if(a[i] == a[i + 1]) continue;
        if(pter == n + 1) {
            if(a[i] * i - pref[i] <= k)
                return 1;
        }
        else {
            if(a[i] * i - pref[i] - a[pter] * (n - pter + 1) + suff[pter] + ((a[pter] - a[i]) - x) * (n - pter + 1) <= k)
                return 1;
            if(pter > i + 1)
                if(a[i] * i - pref[i] - a[pter - 1] * (n - (pter - 1) + 1) + suff[pter - 1] <= k)
                    return 1;
        }
    }
    pter = n;
    for(int i = n; i >= 1; i--) {
        while(pter >= 1 && a[i] - a[pter] <= x) pter--;
        if(a[i] == a[i - 1]) continue;
        if(pter == 0) {
            if(-a[i] * (n - i + 1) + suff[i] <= k)
                return 1;
        }
        else {
            if(a[pter] * pter - pref[pter] - a[i] * (n - i + 1) + suff[i] + ((a[i] - a[pter]) - x) * pter <= k)
                return 1;
            if(pter + 1 < i)
                if(a[pter + 1] * (pter + 1) - pref[pter + 1] - a[i] * (n - i + 1) + suff[i] <= k)
                    return 1;
        }
    }
    return 0;
}

signed main() {
    cin.tie(0), ios_base::sync_with_stdio(0);
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    for(int i = 1; i <= n; i++) {
        pref[i] += a[i];
        pref[i] += pref[i - 1];
    }
    for(int i = n; i >= 1; i--) {
        suff[i] = a[i];
        suff[i] += suff[i + 1];
    }
    int l = 0, r = inf + 1, mid;
    //check(0);
    //exit(0);
    while(l < r) {
        mid = (l + r) >> 1;
        if(check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    cout << l;
}
