#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back

signed main(){
    int t;
    cin >> t;
    
    while(t--){
        int a, b, c, e, extra;
        int x, y, z, one , two;
        cin >> a >> b >> c;
        
        x = a, y = b, z = c;
        extra = z;
        one = 0;
        int cc = c/2;
        e = cc;
        int p = min(e, b);
        
        b -= p;
        extra -= p*2;
        
        one += p*3;
        p = min(a, b/2);
        one += p*3;
        two = 0;
        
        cc = b/2;
        
        p = min(e, x);
        x -= p, y -= p*2;
        two += p*3;
        p = min(y, z/2);
        two += p*3;
        
        cout << max(one, two) << '\n';
    }
}