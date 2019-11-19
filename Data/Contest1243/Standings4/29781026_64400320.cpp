#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e3 + 5;
vector<ll>v;

void solve(ll n){
    for(ll i=2;i*i <= n;i++){
        if(n % i == 0){
            v.push_back(i);
            while(n % i == 0) n /= i;
        }
    }
    if(n != 1){
        v.push_back(n);
    }
}

int main(){
    ll n;
    cin >> n;
    solve(n);
    if(v.size() > 1) cout << 1 << endl;
    else if(v.size() == 1){
        if(v[0] == n) cout << n << endl;
        else{
            cout << v[0] << endl;
        }
    }
    else if(n == 1) cout << 1 << endl;
    return 0;
}