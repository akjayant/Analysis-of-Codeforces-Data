#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <stack>
using namespace std;
typedef long long ll;
int main() {
    ll k;
    cin >> k;
    for (int i = 0; i < k; ++i) {
        string a, b;
        ll n,diff=0;
        cin >> n >>  a >> b;
        for (int j = 0; j < n; ++j) {
            if(a[j]!=b[j])
                diff++;
        }
        if(diff!=2)
            cout << "No\n";
        else{
            ll diff1=0;
            for (int j = 0; j < n; ++j) {
                if(a[j]!=b[j]) {
                    diff1 = j;
                    break;
                }
            }
            ll diff2=0;
            for (int j = diff1+1; j < n; ++j) {
                if(a[j]!=b[j]) {
                    diff2 = j;
                    break;
                }
            }
            if(a[diff1]==a[diff2] && b[diff1]==b[diff2]){
                cout << "Yes\n";
            }
            else cout  << "No\n";
        }
    }
}
