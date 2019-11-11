#include <bits/stdc++.h>
#define ll long long
#define FOR(i,a,b) for(ll i = (a); i<= (b); ++i)
#define L first
#define R second

using namespace std;

const int M=1e5+5;
const ll INF = 1e18;

int main() {
    ios::sync_with_stdio(0);
   // freopen("input.txt","r",stdin);
    int t; ll a,b;
    cin>>t;
    while(t--) {
        cin>>a>>b;
        if(__gcd(a,b) == 1) cout<<"Finite\n";
        else cout<<"Infinite\n";
    }
    return 0;
}
