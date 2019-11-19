#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 2e6;

int a[N];
int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    set<int> st;
    for(int i = 1;i <= n;i ++) {
        cin >> a[i];
    }
    LL sum1 = 0, sum2 = 0;
    sort(a + 1, a + 1 + n);
    reverse(a + 1, a + 1 + n);
    int l = 1, r = n;
    while(l <= r) {
        sum1 += a[l], l ++;
        if(l <= r) {
            sum2 += a[r], r --;
        }
    }
    cout << sum1 * sum1 + sum2 * sum2 << endl;
    return 0;
}