#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define M 1005000
#define ii pair<ll, ll>
#define iii pair<ll, ii>
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(),(x).end()

ll t, n, m, ca, la, cb, lb, x;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin >> t;
    while (t--){
        ca = la = cb = lb = 0;
        cin >> n;
        for (int i = 1; i <= n; i++){
            cin >> x;
            if (x&1) la++; else ca++;
        }
        cin >> m;
        for (int i = 1; i <= m; i++){
            cin >> x;
            if (x&1) lb++; else cb++;
        }
        cout << ca*cb + la*lb << endl;
    }
    
    return 0;
}
