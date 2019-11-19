#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int cnt[1000001];
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL);

    ll n;
    cin >> n;
    ll nn = n;
    int m = sqrt(n);
    for(int d=2; d<=m; d++) {
        while(true) {
            if(n % d == 0) {
                n = n / d;
                cnt[d]++;
            }
            else break;
        }
    }

    int num = 0, i = 0;
    for(int d=2; d<=m; d++) {
        if(cnt[d] > 0) {
            num++;
            i = d;
        }
    }

    if(num == 0) {
        cout << nn;
    }
    else if(num == 1) {
        if(n > 1) { // composite
            cout << 1;
        }
        else cout << i;
    }
    else {
        cout << 1;
    }

    return 0;
}