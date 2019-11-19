#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mod 1000000007

int main() {
    lli n, m;
    cin>>n>>m;
    lli a[100005], b[100000], c[100000];
    a[1] = 2;
    a[2] = 4;
    for(int i=3;i<=100000;i++){
        a[i] = (a[i-1] + a[i-2])%mod;
    }
    lli f1 = a[n];
    lli f2 = (a[n] + 2)%mod;
    b[1] = 0;
    b[2] = 2;
    for(int i=3;i<=100000;i++){
        b[i] = ((b[i-1] + b[i-2])%mod + 2)%mod;
    }
    c[1] = f1;
    c[2] = f2;
    for(int i=3;i<=100000;i++){
        c[i] = (c[i-1] + c[i-2])%mod;
        c[i] = (c[i] - b[n] + mod)%mod; 
    }
    cout<<c[m]%mod<<"\n";
    return 0;
}
