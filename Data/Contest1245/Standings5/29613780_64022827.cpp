#include <bits/stdc++.h>

using namespace std;

#define mx 100005
#define int long long
#define pii pair <int, int>
#define piii pair <int, pii>
#define fi first
#define se second
#define mod 1000000007
#define inf 1e18+19
#define pb push_back
#define pi acos(-1)
#define si(x) scanf("%d", &x)
#define sil(x) scanf("%lld", &x)
#define sid(x) scanf("%lf", &x)
#define mem(ara, x) memset(ara, x, sizeof ara)
#define read() freopen("in.txt", "r", stdin)
#define write() freopen("out.txt", "w", stdout)
#define fst ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

string s;
int ara[mx];

int32_t main(){
    //read();
    //write();
    fst;
    int t;
    cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;
        int g = __gcd(a, b);
        if(g!=1) cout << "inFiNite" << endl;
        else cout << "Finite" << endl;
    }
    return 0;
}










