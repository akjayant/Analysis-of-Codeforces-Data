#include<iostream>
using namespace std;
typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t-- > 0){
        int a, b, c;
        cin >> a >> b >> c;
        int ans = 0;
        int t = min(b, c/2);
        b -= t;
        ans += t*3;
        t = min(a, b/2);
        ans += t*3;
        cout << ans << endl;
    }
    return 0;
}