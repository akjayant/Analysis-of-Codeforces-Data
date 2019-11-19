#include <iostream>
#include <vector>

using namespace std;

int main(){
    int t;
    cin >> t;
    for(int tt = 0; tt < t; ++tt){
        int a, b, c, d, k;
        cin >> a >> b >> c >> d >> k;
        int x = a/c;
        if(a%c)++x;
        int y = b/d;
        if(b%d)++y;
        if(x+y > k) cout << -1 << "\n";
        else cout << x << " " << y << "\n"; 
    }
}