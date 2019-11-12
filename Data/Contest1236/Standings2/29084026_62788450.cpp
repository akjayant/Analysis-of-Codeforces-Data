#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;

long long putere (long long a, long long p){
    long long rez = 1;
    while (p){
        if (p%2 == 1)
            rez = rez * a % MOD;
        a = a * a % MOD;
        p /= 2;
    }
    return rez;
}

int main (){
	long long n, m, ans;
	cin >> n>> m;
	ans = putere(2, m) - 1;
	if (ans < 0)
        ans += MOD;
    cout << putere (ans, n);
	return 0;
}
