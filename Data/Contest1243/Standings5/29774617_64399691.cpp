#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N=1e5+10;
ll n;

int main() {
    ios::sync_with_stdio(0);
    cin>>n;
    if (n==1) cout<<1<<endl;
    else {
        int upb=0; vector<ll> uoc;
        for (ll i=2; i*i<=n; ++i) {
            if (n%i==0) {
                upb++; uoc.push_back(i);
                while (n%i==0) n/=i;
            }
        }
        if (n!=1) {upb++; uoc.push_back(n);}
        if (upb>=2) {
            cout<<1<<endl;
        }
        else {
            cout<<uoc[0]<<endl;
        }
    }
    return 0;
}