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
    int n;
    ara[0] = ara[1] = 1;
    for(int i=2;i<mx;i++){
        ara[i] = (ara[i-1] + ara[i-2])%mod;
    }
    while(cin >> s){
        int ans = 1;
        n = s.size();
        for(int i=0;i<n;i++){
            int j = i, cnt = 0;
            if(s[i] == 'n'){
                while(j < n && s[j]=='n'){
                    cnt++;
                    j++;
                }
                i = j-1;
                ans = (ans * ara[cnt])%mod;
            }
            else if(s[i] == 'u'){
                while(j < n && s[j]=='u'){
                    cnt++;
                    j++;
                }
                i = j-1;
                ans = (ans * ara[cnt])%mod;
            }
            else if(s[i]=='m' || s[i] == 'w'){
                ans = 0;
            }
        }
        cout << ans << endl;
    }
    return 0;
}










