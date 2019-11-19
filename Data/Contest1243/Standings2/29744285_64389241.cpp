#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define mk make_pair
using namespace std;
const int N = 1123456;
const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
inline long long read () {
    char c = getchar();
    long long t = 0, f = 1;
    while (!isdigit(c)) f = (c == '-') ? -1 : 1, c = getchar();
    while (isdigit(c)) t = t * 10 + c - 48, c = getchar();
    return t * f;
}
int a[N];
void solve() {
    int n, m, i, j;
    cin >> n;
    int g = 0;
    for(i = 2; i * i <= n; i ++) {
        if(n % i == 0) {
            g = __gcd(g, i);
            g = __gcd(g, n / i);
        }
    }
    g = __gcd(g, n);
    cout << g << endl;
}
main()
{
    int t = 1;
    while(t -- > 0) {
        solve();
    }
}



