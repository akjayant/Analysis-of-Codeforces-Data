#include <iostream>
using namespace std;
int main(void){
    int t;
    cin >> t;
    while(t-- > 0){
        int a, b, c, d, k, x, y;
        cin >> a >> b >> c >> d >> k;
        x = (a+c-1)/c;
        y = (b+d-1)/d;
        if(x+y <= k){
            cout << x << " " << y << endl;
        }else{
            cout << -1 << endl;
        }
    }
    
}
