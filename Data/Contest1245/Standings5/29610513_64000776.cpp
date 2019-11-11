#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>  
#include <vector>

using namespace std;
typedef long long ll;

int t;
int a,b;

int32_t main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr); cout.tie(nullptr);
    cin >> t;
    while(t--){
        cin >> a >> b;
        if(__gcd(a,b) == 1) cout << "Finite" << endl;
        else cout << "Infinite" << endl;
    }
}
