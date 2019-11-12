#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxN = 1e6+10;
int mod = 1000000000+7;
LL ksm(int a, int b) {
    if(b==0) return 1LL;
    LL ret = 1;
    LL pp = a;
    while(b) {
        if(b%2==1) {
            ret *= pp;
            ret %= mod;
        }
        b/=2;
        pp = pp*pp%mod;
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n, m; cin >> n >> m;
    // (2**m-1)**n
    LL t = (ksm(2,m)-1+mod)%mod;
    LL ans = ksm(t,n);
    cout << ans << endl;


    return 0;
}
