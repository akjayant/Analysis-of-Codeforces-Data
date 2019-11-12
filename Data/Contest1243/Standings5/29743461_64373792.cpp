#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f first
#define se second
#define pb push_back
#define mp make_pair
#define boost cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0)
#define pii pair<ll, ll>

const int N = 1e5 + 1100, mod = 1e9 + 7, inf = 1e9 + 7;
int q, n, a[N];

int main(){
    boost;
    cin >> q;
    while(q--){
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        int ans = 0;
        for(int i = 1; i <= 1000; i++){
            int t = 0;
            for(int j = 1; j <= n; j++){
                if(a[j] >= i)
                    t++;
            }
            if(t >= i){
                ans = i;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
