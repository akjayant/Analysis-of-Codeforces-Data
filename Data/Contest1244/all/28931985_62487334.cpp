#include<bits/stdc++.h>
#define mp make_pair
#define fs first
#define sc second
#define pb push_back
#define debug(x) cout<<#x<<" = "<<(x)<<endl
#define mod 1000000007
#define INF 1e18
#define ALPHABET_SIZE 26


using namespace std;
typedef long long ll;

/* Look for:
* the exact constraints (multiple sets are too slow for n=10^6 :( ) 
* special cases (n=1?)
* overflow (ll vs int?)
* array bounds
* if you have no idea just guess the appropriate well-known algo instead of doing nothing :/
*/

long long cost[100005][5], jaw[100005];
vector<int> hub[100005];
int ke[100005];

void dfs(int now, int par){

    for(int i = 0; i < hub[now].size(); i++){
        int cur = hub[now][i];
        if(cur == par) continue;
        ke[now] = cur;
        dfs(cur, now);
    }
}

int main(){
    int n; cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> cost[i][0];
    }
    for(int i = 1; i <= n; i++){
        cin >> cost[i][1];
    }
    for(int i = 1; i <= n; i++){
        cin >> cost[i][2];
    }

    for(int i = 1; i < n; i++){
        int u,v; cin >> u >> v;
        hub[u].pb(v);
        hub[v].pb(u);
    }

    int nyak = 0;
    int mulai;
    for(int i = 1; i <= n; i++){
        if(hub[i].size() == 1){
            nyak++;
            mulai = i;
        }
    }

    memset(ke, -1, sizeof(ke));
    dfs(mulai, -1);

    if(nyak != 2){
        cout << "-1\n";
        return 0;
    }else{
        long long ans = 1e18;
        long long kiri = -1, kanan = -1;
        for(int i = 0; i <= 2; i++){
            for(int j = 0; j <= 2; j++){
                if(i == j) continue;

                long long now = cost[mulai][i] + cost[ke[mulai]][j];
                int a = i, b = j;

                int node = ke[ke[mulai]];
                while(node != -1){
                    int cur = 3 - a - b;
                    now = now + cost[node][cur];
                    a = b;
                    b = cur;
                    node = ke[node];
                }
                if(now < ans){
                    kiri = i;
                    kanan = j;
                    ans = now;
                }
                // cout << i << " " << j << " " << now << " here\n";
                // ans = min(ans, now);
            }
        }
        // cout << mulai << " here\n";
        jaw[mulai] = kiri;
        jaw[ke[mulai]] = kanan;
        int a = kiri;
        int b = kanan;
        int node = ke[ke[mulai]];
        while(node != -1){
            int cur = 3 - a - b;
            a = b;
            b = cur;
            jaw[node] = cur;
            node = ke[node];
        }
        cout << ans << "\n";
        for(int i = 1; i <= n; i++){
            if(i != 1) cout << " ";
            cout << jaw[i] + 1;
        }
        cout << "\n";
    }


}
