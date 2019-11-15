#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <stack>
using namespace std;
typedef long long ll;
int main() {
    ll k;
    cin >> k;
    for (int i = 0; i < k; ++i) {
        ll n;
        cin >> n;
        ll a[n];
        for (int j = 0; j < n; ++j) {
            cin >> a[j];
        }
        for (int l = 1000; l >= 1; --l) {
            ll c=0;
            for (int j = 0; j < n; ++j) {
                if(a[j]>=l)
                    c++;
            }
            if(c>=l) {
                cout << l << "\n";
                goto end2;
            }
        }

        end2:;
    }
}
