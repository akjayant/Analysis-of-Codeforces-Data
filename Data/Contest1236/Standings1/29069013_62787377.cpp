#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define pb push_back
#define F first
#define S second
typedef pair<int, int> pi;
 
ll mod = 1e9 + 7;

bool comp(pi a, pi b){
    return a.F < b.F || (a.F == b.F && a.S < b.S);
}

int main(){
    ios_base :: sync_with_stdio(false); 
    int t;
    cin >> t;
    while(t--){
        ll a, b, c;
        cin >> a >> b >> c;
        ll x = min(c/2, b);
        ll y = min(b/2, a);
        cout << max(3*x + 3*min(a, (b - x)/2), 3*y + 3*min(c/2, b - 2*y)) << endl;
    }
}