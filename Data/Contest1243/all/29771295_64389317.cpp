/*input
5
*/
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define pb push_back
#define f first
#define s second
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

signed main() {
    IOS;
    int n;
    cin >> n;
    set<int> s;
    for(int i = 2 ; i * i <= n  ; i++){
        if(n % i == 0){
            s.insert(i);
            s.insert(n/i);
        }
    }
    int g = n;
    for(auto x : s){
        g = __gcd(g,x);
    }
    cout << g << endl;
return 0;
}
