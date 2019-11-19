#include "bits/stdc++.h"
using namespace std;

long long n;

int main() {
    ios::sync_with_stdio(0);
    cin>>n;
    long long ans=n;
    for(long long i=2;i*i<=n;i++) {
        if(n%i==0) {
            ans = __gcd(ans,i);
            ans = __gcd(ans,n/i);
        }
    }
    cout<<ans<<endl;
    return 0;
}
