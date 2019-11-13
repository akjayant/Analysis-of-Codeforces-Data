#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


long long gcd(long long a, long long b){
    if(b==0) return a;
    return gcd(b,a%b);
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);
    
    
    int q;
    cin>>q;
    while(q--){
        int a,b;
        cin>>a>>b;
        ll g = gcd(a,b);
        if(g==1){
            cout << "Finite\n";
        }
        else cout <<"Infinite\n";
    }
}