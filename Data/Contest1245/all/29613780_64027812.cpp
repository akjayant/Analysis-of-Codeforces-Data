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

string str;
char ara[mx];

int32_t main(){
    //read();
    //write();
    //fst;
    int t;
    cin >> t;
    while(t--){
        int a, b, c, n, r, p, s;
        cin >> n >> a >> b >> c >> str;
        r = p = s = 0;
        for(int i=0;i<n;i++){
            if(str[i]=='R') r++;
            if(str[i]=='S') s++;
            if(str[i]=='P') p++;
        }
        int ta = min(a, s);
        int tb = min(b, r);
        int tc = min(c, p);
        if(ta + tb + tc >= (n+1)/2){
            cout << "YES" << endl;
            for(int i=0;i<n;i++){
                ara[i] = '#';
                if(str[i]=='R' && b) {
                    ara[i] = 'P';
                    b--;
                }
                if(str[i]=='S' && a) {
                    ara[i] = 'R';
                    a--;
                }
                if(str[i]=='P' && c) {
                    ara[i] = 'S';
                    c--;
                }
            }
            for(int i=0;i<n;i++){
                if(ara[i]=='#'){
                    if(a) {
                        ara[i] = 'R';
                        a--;
                    }
                    else if(b) {
                        ara[i] = 'P';
                        b--;
                    }
                    else if(c) {
                        ara[i] = 'S';
                        c--;
                    }
                }
                cout << ara[i];
            }
            cout << "\n";
        }
        else cout << "NO" << endl;
    }
    return 0;
}










