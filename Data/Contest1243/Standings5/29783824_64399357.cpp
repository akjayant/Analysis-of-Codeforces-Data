#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <stack>
#include <cmath>
using namespace std;
typedef long long ll;
int main() {
    ll n,o;
    cin >> n;
    o=n;
    ll sq=sqrtl(n);
    ll cnt = 0,last;
    for (ll j = 2;  j<= sq; j++) {
        if(o%j==0)
            cnt++,last=j;
        while(o%j==0)
            o/=j;
    }
    if(o!=1 && o!=n){
        cnt++;
    }
    if (cnt==0)
        cout << n;
    else if (cnt==1){
        cout << last;
    }
    else cout << 1;
}