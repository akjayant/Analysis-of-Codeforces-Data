#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<pll,ll> plll;
typedef pair<pll,pll> ppll;
typedef long double ld;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define fst first
#define snd second
#define ins insert
#define pb push_back

const int N = 300;
const int MOD = 1e9 + 7;
int ans[N][N];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    int n;
    cin >> n;
    int cnt = 1;
    for(int j = 0;j < n / 2; ++j){
        for(int i = 0;i < n; ++i)ans[i][j] = cnt++;
    }
    for(int j = n / 2;j < n; ++j){
        for(int i = n - 1;i >= 0; --i)ans[i][j] = cnt++;
    }
    for(int i = 0;i < n; ++i){
        for(int j = 0;j < n; ++j)cout << ans[i][j] << " ";
        cout << "\n";
    }
    return 0;
}
