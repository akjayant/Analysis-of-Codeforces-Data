#include <bits/stdc++.h>
#include <vector>
using namespace std;

long long ans;
long long m, n, a, b, c, k_1, k_2, i;
long long mod = 1000000007;

int main(){
    cin>>n>> m;
    a = 0;
    b = 2;
    for (i=0; i<m; i++){
        c = (a+b) % mod;
        a = b;
        b = c;
    }
    k_1 = b;

    a = 0;
    b = 2;
    for (i=0; i<n; i++){
        c = (a+b) % mod;
        a = b;
        b = c;
    }
    k_2 = b;
    cout<<(k_1+k_2-2)%mod;
}
