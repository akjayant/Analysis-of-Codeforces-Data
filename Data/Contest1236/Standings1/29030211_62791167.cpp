#include <bits\stdc++.h>

#define sc second
#define fr first
#define mk make_pair
#define pb push_back
#define int long long

using namespace std;

const int N = (1e6 + 5);
const int inf = (1e9 + 7);

int n,m;
int ans;

int binpow (int a,int b) {
    int res = 1;
    while (b) {
        if (b & 1) res *= a;
        a *= a;
        b >>= 1;
        res %= inf;
        a %= inf;
    }
    return (res % inf);
}
main () {
    cin >> n >> m;

    cout << binpow((binpow(2,m) + inf - 1) % inf,n) << endl;
}
