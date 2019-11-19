#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef unsigned long long int uLL;
typedef unsigned int uint;



int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--){
        int a, b, c, d, k;
        cin >> a >> b >> c >> d >> k;
        int x = a/c+(a%c > 0);
        int y = b/d+(b%d > 0);
        if(x + y > k){
            cout << -1 << '\n';
        }
        else{
            cout << x << " " << y << '\n';
        }
    }
    return 0;
}
