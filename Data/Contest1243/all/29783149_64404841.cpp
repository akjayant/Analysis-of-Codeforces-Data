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

string s, t;
vector <pii> v;

int32_t main(){
    //read();
    fst;
    int k;
    cin >> k;
    while(k--){
        int n;
        v.clear();
        cin >> n >> s >> t;
        for(int i=0;i<n;i++){
            if(s[i]!=t[i]){
                v.push_back({s[i] - 'a', t[i] - 'a'});
            }
        }
        if(((int) v.size()) == 2){
            if(v[0] == v[1]){
                cout << "Yes" << endl;
                continue;
            }
        }
        else if(((int) v.size()) == 0){
            cout << "Yes" << endl;
            continue;
        }
        cout << "No" << endl;
    }
    return 0;
}















