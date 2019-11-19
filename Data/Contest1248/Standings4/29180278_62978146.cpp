#include <bits/stdc++.h>
#define ff first
#define ss second
#define endl '\n'
using namespace std;
const long long INF = (long long) 1e18;
const int mod = (int) 1e9+7;
const int MAXN = (int) 3e5+5;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
ll a[2], b[2];


void solve(){
    int n, m;
    a[0] = a[1] = b[0] = b[1] = 0;
    cin>>n;
    for(int i = 0; i < n; i++){
        int ali;
        cin>>ali;
        if(ali%2) a[1]++;
        else a[0]++;
    }
    cin>>m;
    for(int i = 0; i < m; i++){
        int ali;
        cin>>ali;
        if(ali % 2) b[1]++;
        else b[0]++;
    }

    cout<< a[0]*b[0] + a[1]*b[1]<<endl;


}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    #ifdef Local
        freopen("../IO/int.txt","r",stdin);
        freopen("../IO/out.txt","w",stdout);
    #endif

    int t;
    cin>>t;
    while(t--){
        solve();
    }

    #ifdef Local
        cout<<endl<<fixed<<setprecision(2)<<1000.0 * clock() / CLOCKS_PER_SEC<< " milliseconds ";
    #endif
}