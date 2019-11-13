#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int MOD = 1000000007;

int add(int a, int b){
    return (a+b)%MOD;
}

int mul(int a, int b){
    return ((ll)a*b)%MOD;
}

int fib[100005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;

    string s;
    cin >> s;
    int n = s.size();
    for(auto c : s){
        if(c == 'm' || c == 'w'){
            cout << 0;
            return 0;
        }
    }
    vector <int> vec;
    char tren = s[0];
    int sz = 1;
    for(int i=1; i<n; i++){
        if(s[i] != s[i-1]){
            if(tren == 'n' || tren == 'u') vec.push_back(sz);
            sz = 0;
            tren = s[i];
        }
        sz++;
    }
    if(tren == 'n' || tren == 'u') vec.push_back(sz);
    int res = 1;
    fib[0] = fib[1] = 1;
    for(int i=2; i<=n; i++){
        fib[i] = add(fib[i-1], fib[i-2]);
    }
    for(auto c : vec){
        res = mul(res, fib[c]);
    }
    cout << res;
    return 0;
}
