#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

int32_t main() {
    int k;
    cin >> k;
    while(k--) {
        int n;
        cin >> n;
        int a[n];
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a, a + n);
        int len = 0;
        for(int i = n-1; i >= 0; --i) {
            if(a[i] > len) {
                len++;
            } else {
                break;
            }
        }
        cout << len << '\n';
    }
    return 0;
}