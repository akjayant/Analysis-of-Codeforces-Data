#include<bits/stdc++.h>
using namespace std;

#define N 200123
#define mod 1000000007


long long subm(long long a, long long b){
	a -= b;
  	if (a < 0) a += mod;
	return a;
}

int main(){	
    ios::sync_with_stdio(false);
	cin.tie(0);
    if(fopen("input.in", "r")){
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    }
    int n, m;
    long long fib[N], ans = 2, row, col;
    cin >> n >> m;
    fib[0] = 0;
    fib[1] = 1;
    fib[2] = 2;
    for(int i = 3 ; i < N ; i++){
    	fib[i] = (fib[i-1] + fib[i-2]) % mod;
    }
    row = (fib[m]*2) % mod;
    col = (fib[n]*2) % mod;
    ans = (row + col) % mod;
    cout << subm(ans, 2) << endl;
    return 0;
}