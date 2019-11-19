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
        int n;
        string st;
        cin >> n >> st;
        int l = -1, r = 0;
        for(int i = 0; i < n; i++){
            if(st[i] == '1'){
                if(l == -1)
                    l = i;
                r = i;
            }
        }
        if(l == -1){
            cout << n << "\n";
        }else cout << max(max(abs(n - 1 - l + 1), abs(r - 0 + 1)) * 2, n) << "\n";
    }
    return 0;
}

