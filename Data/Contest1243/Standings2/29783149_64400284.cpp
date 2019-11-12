#include <bits/stdc++.h>

using namespace std;

#define mx 100005
//#define int long long
#define pii pair <int, int>
#define piii pair <int, pii>
#define fi first
#define se second
#define mod 1000000007
#define inf 1e18+19
#define pb push_back
#define si(x) scanf("%lld", &x)
#define mem(ara, x) memset(ara, x, sizeof ara)
#define read() freopen("in.txt", "r", stdin)
#define write() freopen("out.txt", "w", stdout)
#define fst ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


int cnt[1004];

int32_t main(){
    //read();
    fst;
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        mem(cnt, 0);
        for(int i=1;i<=n;i++){
            int a;
            cin >> a;
            cnt[a]++;
        }
        for(int j=n;j>=1;j--){
            cnt[j] += cnt[j+1];
            if(cnt[j] >= j) {
                cout << j << endl;
                break;
            }
        }
    }
    return 0;
}















