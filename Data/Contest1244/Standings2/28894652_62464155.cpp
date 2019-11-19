#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    int t; cin>>t;
    while (t--) {
        int a,b,c,d,k; cin>>a>>b>>c>>d>>k;
        int x=(a+c-1)/c;
        int y=(b+d-1)/d;
        if (x+y>k) cout<<"-1\n";
        else cout<<x<<" "<<y<<"\n";
    }
    return 0;
}