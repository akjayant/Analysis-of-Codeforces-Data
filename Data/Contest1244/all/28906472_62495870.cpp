#include <bits/stdc++.h>

using namespace std ;

#define N 100005
#define pb push_back
#define ll long long
#define mod 1000000007
#define pll pair<ll, ll>
#define double long double
#define fi first
#define se second
#define INF 1e18
#define Base 1200

bool mark[N];

int main(){
    ios_base :: sync_with_stdio(false);
    ll n , p , w , d;
    cin >> n >> p >> w >> d;
    memset(mark , false , sizeof mark);

    if((p + 1) / w > n)
        return cout << -1 << endl , 0;

    ll x = p / w ;
    ll y = 0;
    ll r = p % w ;

    while(r % d != 0){
        if(mark[r % d])
            return cout << -1 << endl , 0;
        mark[r % d] = true;

        r += w;
        x--;

        if(x < 0)
            return cout << -1 << endl , 0;
    }

    y = r / d;

    if(x + y <= n){
        ll z = n - (x + y);
        cout << x <<' ' << y <<' ' << z << endl;
    }

    else
        cout << -1 << endl;
    return 0;
}


