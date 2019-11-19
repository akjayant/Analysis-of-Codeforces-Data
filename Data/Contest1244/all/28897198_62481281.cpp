#include<iostream>
#include<algorithm>
using namespace std;

const int maxn = 1e5 + 5;
long long n, k, a[maxn];

int main() {
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n);
    long long num = 1;
    for(int lef = 0, rig = n-1; lef < rig; num++) {
        long long lefex = a[lef+1] - a[lef];
        long long lefdj = lefex * num;
        if(lefdj >= k) {
            a[lef] += k / num;
            cout << a[rig] - a[lef] << endl;
            return 0;
        } else {
            k -= lefdj;
            lef++;
        }
        if(lef == rig) break;
        long long rigex = a[rig] - a[rig-1];
        long long rigdj = rigex * num;
        if(rigdj >= k) {
            a[rig] -= k / num;
            cout << a[rig] - a[lef] << endl;
            return 0;
        } else {
            k -= rigdj;
            rig--;
        }
    }
    cout << 0 << endl;
    return 0;
}