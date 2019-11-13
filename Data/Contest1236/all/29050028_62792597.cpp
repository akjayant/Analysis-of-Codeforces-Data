/*input
2 2

*/
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define f first
#define s second
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
int const mod = 1e9+7;
int power(int x, int y, int mod = 2e18){ int ans = 1;x %= mod;while(y){if(y&1)ans = (x * ans) % mod;x = (x * x) % mod;y >>= 1;}return ans;}
int gcd(int a , int b){if(a==0)return b;return gcd(b%a,a);}

signed main() {
    IOS;
    int n,m;
    cin >> n >> m;
    int t = power(2,m,mod) - 1 + mod;
    t %= mod;
    int g = power(t,n,mod);
    cout << g << endl;
return 0;
}