#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 1000000007;

int64_t cal(int64_t L, int64_t R) {
    if(R == 0) {
        return 1;
    }
    if(R == 1) {
        return L % MOD;
    }
    int64_t p = cal(L, R/2);
    int64_t pp = p*p%MOD;
    if (R&1) {
        return pp*L%MOD;
    }
    return pp;
}

int main(){
    int64_t a, b;
    cin >> a >> b;
    int64_t p = cal(2, b);
    p = (p+MOD-1)%MOD;
	cout << cal(p, a) << endl;
    return 0;
}
