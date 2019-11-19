#include <bits/stdc++.h>
using namespace std;
long long n, m, ans, fib[100005], M=1000000007;
int main (){
ios::sync_with_stdio(0);
cin.tie(0); cout.tie(0);
cin >> n >> m;
fib[0]=fib[1]=1;
for (int i=2; i<=(max(n, m)); i++) fib[i]=(fib[i-1]+fib[i-2])%M; 
ans=fib[m]+fib[n]-1; ans*=2; ans%=M;
cout << ans;
return 0;
}

