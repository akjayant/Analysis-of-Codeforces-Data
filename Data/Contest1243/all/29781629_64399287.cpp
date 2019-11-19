//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
//#include <optimization.h>
#pragma GCC optimize("O3")
#define chervyak 6
#define sasha chervyak
#define y1 jhgfds
#define prev maAslo
#define int long long
#define ull uint64_t
#define ld long double
#define pb push_back
#define eb emplace_back
#define all(v) v.begin(), v.end()
#define rep(i, n) for(int i = 0; i < n; i++)

using namespace std;
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
//cout << clock()*1000/CLOCKS_PER_SEC << '\n';


int gcd(int a, int b){
    int c;
    while(b != 0){
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> a;
    a.pb(n);
    for(int i = 2; i*i <= n; i++){
        if(n % i == 0){
            a.pb(i);
            a.pb(n / i);
        }
    }
    int nod = n;
    rep(i, a.size()){
        nod = gcd(nod, a[i]);
    }
    cout << nod;
}
















