#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define F first
#define S second
#define zak ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int N = 1e3 + 5, M = 1e5 + 5, mod = 1e9 + 7;

int main(){
    zak
    ll n;
    cin >> n;
    while(n--)
    {
        ll a,b,c;
        cin >> a >> b >> c;
        ll aa = a,bb = b,cc = c;
        ll cnt = min(b,c/2);
        b-=cnt;
        ll ans = cnt*3 + (min(a,b/2)) * 3;
        ll cnt1 = min(aa,bb/2);
        bb-=cnt1*2;
        ll ans1 = cnt1*3 + (min(bb,cc/2))*3;
        cout << max(ans,ans1) << endl;
    }
}

