#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
long long fib (long long n){
    long long a=1, b=1, c=2, i;
    if (n==1) return 1;
    for (i=2; i<=n; i++){
        c = (a + b) % MOD;
        a = b;
        b = c;
    }
    return c;
}
int main (){
	long long n, m;
	cin >> n >> m;
    cout << ((long long)(2) * ((long long)fib (n) + fib (m)) - 2)%MOD;
	return 0;
}
