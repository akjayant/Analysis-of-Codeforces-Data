#include <iostream>

using namespace std;

int T,a,b,c,d,k;
int main(){
    cin >> T;
    while (T--){
        cin >> a >> b >> c >> d >> k;
        if ((a/c)+(a%c>0)+(b/d)+(b%d>0)<=k)
            cout << (a/c)+(a%c>0) << " " << (b/d)+(b%d>0) << endl;
        else cout << -1 << endl;
    }
}