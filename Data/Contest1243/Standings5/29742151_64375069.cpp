//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
#define pb push_back
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define itmin(x,y) (x) = min((x),(y));
#define itmax(x,y) (x) = max((x),(y));
#define cotu cout
#define itn int
#define speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int INF = 1e9 + 7;

void solve(){
    int n;
    cin>>n;
    vi v(n);
    for(int i = 0; i < n; i++) cin>>v[i];
    sort(rall(v));
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(v[i]>=i+1) ans = i+1;
    }
    cout<<ans<<endl;
}

int main(){
    int t = 1;
    cin>>t;
    while(t--) solve();
}