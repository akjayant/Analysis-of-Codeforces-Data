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
#define INF 10000000000000000
#define Base 1200

int main(){
    ios_base :: sync_with_stdio(false);
    int testcase;
    int a , b , c , d , k;
    cin >> testcase;
    while(testcase--){
        cin >> a >> b >> c >> d >> k;
        int ans1 = ceil(1.0 * a / c);
        int ans2 = ceil(1.0 * b / d);
        if(ans1 + ans2 > k)
            cout << -1 << endl;
        else
            cout << ans1 <<' ' << ans2 <<endl;

    }
    return 0;
}


