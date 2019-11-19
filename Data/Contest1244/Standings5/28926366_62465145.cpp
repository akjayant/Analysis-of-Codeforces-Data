#include<bits/stdc++.h>
using namespace std;
typedef long long ll;




signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    int q;
    cin>>q;
    while(q--){
        int a,b,c,d,k;
        cin>>a>>b>>c>>d>>k;
        ll sum = (a+c-1)/c + (b+d-1)/d;
        if(sum<=k){
            cout << (a+c-1)/c << " " << (b+d-1)/d <<"\n";
        }
        else cout << -1 << "\n";

    }
}