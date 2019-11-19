#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0)
#define f first
#define se second
#define lb lower_bound
#define ub upper_bound
#define pii pair<int,int>

const int N = 1e5 + 1000, mod = 1e9 + 7;

ll bin_pow(int x, int y){
    if(y == 0)
        return 1;
    if(y == 1)
        return x;
    if(y % 2 == 0){
        ll z = bin_pow(x, y / 2);
        return (z * z) % mod;
    }
    return (bin_pow(x, y - 1) * x) % mod;
}




int main(){
    boost;
    int q;
    cin >> q;
    while(q--){
        int a, b, c, d, k;
        cin >> a >> b >> c >> d >> k;
        int sum = (a + c - 1) / c + (b + d - 1) / d;
        if(sum <= k){
            cout << (a + c - 1) / c << " " << (b + d - 1) / d << "\n";
        }else cout << "-1\n";
    }
    return 0;
}

