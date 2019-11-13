#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    int t; cin>>t;
    while (t--) {
        int a,b,c; cin>>a>>b>>c;
        int res=0;
        for (int x=0; x<=a; ++x) {
            for (int y=0; 2*y<=c; ++y) {
                if (2*x+y<=b) res=max(res, 3*x+3*y);
            }
        }
        cout<<res<<"\n";
    }
    return 0;
}