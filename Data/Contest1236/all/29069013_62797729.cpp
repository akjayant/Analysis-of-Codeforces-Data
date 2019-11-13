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

ll func(ll x, ll y){
    if (y == 0)
        return 1;
    ll temp = func(x, y/2);
    temp = (temp*temp)%mod;
    if (y%2){
        return (temp*x)%mod;
    }
    else
        return temp%mod;
}

int main(){
    ios_base :: sync_with_stdio(false); 
    ll n, m;
    cin >> n >> m;
    cout << func(func(2, m) - 1ll, n) << endl;

}