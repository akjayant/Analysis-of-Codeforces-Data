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
ll a[N];

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


bool check(ll x){

}

int main(){
    boost;
    ll n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    int l = 1, r = n, x = 0, y = 0;
    while(a[l] == a[l + 1])
        l++;
    while(a[r] == a[r - 1])
        r--;
    x = l;
    y = n - r + 1;
    while(x + y <= n){
        if(x <= y){
            k -= (a[l + 1] - a[l]) * x;
            if(k <= 0){
                k += (a[l + 1] - a[l]) * x;
                ll p = k / x;
                a[l] += p;
                cout << a[r] - a[l];
                return 0;
            }
            a[l] = a[l + 1];
            while(a[l] == a[l + 1] && x + y <= n){
                l++;
                x++;
            }
        }else{
            k -= (a[r] - a[r - 1]) * y;
            if(k <= 0){
                k += (a[r] - a[r - 1]) * y;
                ll p = k / y;
                a[r] -= p;
                cout << a[r] - a[l];
                return 0;
            }
            a[r] = a[r - 1];
            while(a[r] == a[r - 1] && x + y <= n){
                r--;
                y++;
            }
        }
    }
    cout << a[r] - a[l];
    return 0;
}

