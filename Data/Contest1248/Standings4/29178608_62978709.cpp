#pragma warning(disable:4996)
#include<bits/stdc++.h>
#define upf(a,b,c) for(int a=b;a<=c;++a)
#define drf(a,b,c) for(int a=b;a>=c;--a)
#define mem(a,b) memset(a,b,sizeof(a))
#define Tcase(n) for(int _=1;_<=n;++_)
#define ll long long
#define ull unsigned long long
#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
const int mod(1e9 + 7);
const int maxn(5e5 + 5);
const ll INF(0x3fffffffff);
using namespace std;
ll powmod(ll a, ll b) { ll res = 1; a %= mod; assert(b >= 0); for (; b; b >>= 1) { if (b & 1)res = res * a % mod; a = a * a % mod; }return res; }
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
int n, T;

int main() {
#ifndef ONLINE_JUDGE
    freopen("./ACM.in", "r", stdin);
    freopen("./ACM.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
    while (T--) {
        cin >> n;
        int p;
        ll num0 = 0, num1 = 0;
        upf(i, 1, n) {
            cin >> p;
            if (p % 2)num1++;
            else num0++;
        }
        ll sum = 0;
        cin >> n;
        upf(i, 1, n) {
            cin >> p;
            if (p % 2)sum += num1;
            else sum += num0;
        }
        cout << sum << endl;
    }
}