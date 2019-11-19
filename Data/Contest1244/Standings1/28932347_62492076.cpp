#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN = 100000;
int n;
long long k;
int a[MAXN];

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    int l = a[0];
    int lb = 1;
    int lp = 0;
    long long ls = 0;
    int r = a[n - 1];
    int rb = 1;
    int rp = n - 1;
    long long rs = 0;
    while (l < r) {
        if (lb < rb) {  // increase l
            long long gap = a[lp + 1] - l;
            if (k > gap * lb) {
                k -= gap * lb;
                lb += 1;
                lp += 1;
                l = a[lp];
            } else {
                l += k / lb;
                break;
            }
        } else {  // decrease r
            long long gap = r - a[rp - 1];
            if (k > gap * rb) {
                k -= gap * rb;
                rb += 1;
                rp -= 1;
                r = a[rp];
            } else {
                r -= k / rb;
                break;
            }
        }
    }
    cout << (r > l ? r - l : 0) << endl;
    return 0;
}
