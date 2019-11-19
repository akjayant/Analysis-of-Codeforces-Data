#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=(ll)1e9+7;


void solve(){
    int a,b,c,d,k;
    cin>>a>>b>>c>>d>>k;
    int x,y;
    x=(a-1)/c+1;
    y=(b-1)/d+1;
    if(x+y<=k){
        cout<<x<<" "<<y<<endl;
    }else{
        cout<<-1<<endl;
    }
    return;
}


int main() {
    int q; cin>>q;
    for (int i = 0; i < q; ++i) {
        solve();
    }
    return 0;
}
