#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define mk make_pair
#define mod 1000000007
#define ff first
#define ss second

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

ll modpow(ll a, ll b){

    ll ans=1;
    while(b){
        if(b&1){
            ans=(ans*a)%mod;
        }
        a=(a*a)%mod;
        b=b/2;
    }
    return ans;
}

ll fib[100010];

ll ans[100010];

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    ll n,m;
    cin>>n>>m;

    fib[0] = 2;
    fib[1] = 2;

    for(int i = 2; i <= n; i++) {
        fib[i] = (fib[i-1] + fib[i-2])%mod;
    }

    ans[1] = fib[n];
    ans[2] = (fib[n] + 2)%mod;
    ans[3] = (fib[n] + 4)%mod;

    for(int j = 4; j <= m; j++) {
        ans[j] = (2*ans[j-1] - ans[j-3])%mod;

        if(ans[j] < 0)  ans[j] += mod;
    }

    cout<<ans[m]<<endl;

    // int dx[] = {-1, 1, 0, 0};
    // int dy[] = {0, 0, -1, 1};

    // int n,m;

    // n = 7;

    // for(m = 1; m <= 3; m++) {

    //     int ans = 0;

    //     int cells = n*m;
        
    //     for(int j = 0; j < (1<<cells); j++) {

    //         vector<bool> cellv(n*m, false);

    //         for(int k = 0; k < cells; k++) {
    //             if((1<<k) & j) {
    //                 cellv[k] = true;
    //             } else cellv[k] = false;
    //         }


    //         int fl = 0;

    //         for(int i1 = 0; i1 < n; i1++) {
    //             for(int j1 = 0; j1 < m; j1++) {
    //                 int cellc = i1*m + j1;

    //                 bool color = cellv[cellc];
    //                 int cnt = 0;
    //                 for(int k1 = 0; k1 < 4; k1++) {
    //                     if(dx[k1] + i1 < 0 || dx[k1] + i1 >= n || dy[k1] + j1 < 0 || dy[k1] + j1 >= m) continue;

    //                     int cellc1 = (dx[k1]+i1)*m + (dy[k1]+j1);
    //                     if(cellv[cellc1] == color) cnt++;
    //                 }

    //                 if(cnt > 1) {
    //                     fl = 1;
    //                     break;
    //                 }
    //             }

    //             if(fl) break;
    //         }

    //         if(fl == 0) ans++;

    //     }

    //     cout<<n<<" "<<m<<" "<<ans<<endl;
    // }

    


}
