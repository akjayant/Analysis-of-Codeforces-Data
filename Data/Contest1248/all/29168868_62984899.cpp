#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 1e5 + 5;

int a[N], b[N];

int main() {
    int t; scanf("%d", &t);
    while(t--) {
        int n, m;
        ll ans = 0;
        scanf("%d", &n);
        ll oa = 0, ea = 0;
        ll ob = 0, eb = 0;
        for(int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            if(a[i] & 1) oa++;
            else ea++;
        }
        scanf("%d", &m);
        for(int i = 1; i <= m; i++) {
            scanf("%d", &b[i]);
            if(b[i] & 1) ob++;
            else eb++;
        }
        cout << oa * ob + ea * eb << endl;
    }
    return 0;
}
