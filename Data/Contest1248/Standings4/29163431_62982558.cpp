#include <bits/stdc++.h>

using namespace std ;

#define pb push_back
#define ll long long
#define mod 1000000007
#define pii pair<int, int>
#define double long double
#define fi first
#define se second
#define INF 1e9
#define N 100005

int a[N];

int main(){
    ios_base :: sync_with_stdio(false);
    int n ;
    cin >> n ;
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }

    sort(a , a + n);

    int mid  = n / 2;

    ll x = 0 , y = 0;
    for(int i = 0 ; i < mid ; i++){
        x += a[i];
    }

    for(int i = mid ; i < n ; i++){
        y += a[i];
    }

    ll ans = x * x + y * y ;
    cout << ans << endl;
    return 0;
}
