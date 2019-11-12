#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int MOD = 1e9+7;

int add(ll a, int b){
    return (a+b + 2LL*MOD) % MOD;
}
int mul(ll a, int b){
    return (a*b) % MOD;
}

int bp(int a, int b){
    if(b == 0)
        return 1;
    int x = bp(a, b/2);
    x = mul(x, x);
    return b&1 ? mul(x, a) : x;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;cin >> n >> m;
    cout << bp(add(bp(2, m), -1), n) << "\n";
}

