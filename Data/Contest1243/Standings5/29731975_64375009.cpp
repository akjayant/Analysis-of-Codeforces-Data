#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define __ ios_base::sync_with_stdio(0);cin.tie(0);
#define forn(i,a,n) for(int i =a; i < n; i++)
#define fi first
#define se second
#define pb push_back
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long int lli;
typedef pair<int,int> pii;
#define MOD 1000000007 
#define MAXN

void solve(){
    int n;
    cin >> n;
    vi a(n);
    forn(i,0,n) cin >> a[i];
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    int ans =0;
    forn(i,0,n){
        int x = ans+1;
        if(a[i] >= x){
            ans = x;
        }
        else{
            break;
        }
    }
    cout << ans << endl;
}
int main(){__
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
