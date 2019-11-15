#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define E "\n"

using namespace std;
const long long MOD = (long long)1e9 + 7;

int t, n, a[1009];

int fun(int cur)
{
    for (int i = 0; i < cur; i++) {
        if (a[i] < cur) return false;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a, a + n);
        reverse(a, a + n);
        int l = 1, r = 1001;
        while (l + 1 < r) {
            int mid = (l + r)/2;
            if (fun(mid)) l = mid;
            else r = mid;
        }
        cout << l << E;
    }
    //system("pause");
    return 0;
}