#include <iostream>
using namespace std;

int ceil(int, int);

int main(){
    int test;
    cin >> test;
    for(int t = 0; t < test; t++){
        int a, b, c, d, k;
        cin >> a >> b >> c >> d >> k;
        int x = ceil(a, c);
        int y = ceil(b, d);
        if(x + y <= k)
            cout << x << ' ' << y << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}

int ceil(int a, int b){
    int q = a / b;
    int r = a % b;
    if(r == 0)
        return q;
    else
        return q + 1;
}

