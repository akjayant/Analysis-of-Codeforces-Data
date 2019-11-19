#include<bits/stdc++.h>
#define fi first
#define se second
#define all(x) x.begin() , x.end()
#define rall(x) x.rbegin() , x.rend()
#define pb push_back
typedef long long ll;
typedef long double ld;
using namespace std;
const int N = 1e5 + 1;


signed main() {
    #define int long long
    ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
    int n;
    cin >> n;
    ll k;
    cin >> k;
    vector < int > a(n);
    for(auto &i : a)cin >> i;
    sort(all(a));
    vector<pair<int,int>>x;
    map < int , int > mr;
    for(auto &i : a)mr[i]++;
    for(auto &i : mr)x.pb({i.fi , i.se});
    int i = 0 , j =  x.size() - 1;
    int f = x[0].se , s = x[x.size() - 1].se;
    int ans = x[x.size() - 1].fi - x[0].fi;
    while(i < j){
        if(k < min(f , s))
            return cout << ans , 0;
        if(f < s){
            if(k < (x[i + 1].fi - x[i].fi) * f){
                ans -= k / f;
                return cout << ans , 0;
            }else{
                ans -= (x[i + 1].fi - x[i].fi);
                k -= (x[i + 1].fi - x[i].fi) * f;
                f += x[i + 1].se;
                i++;
            }
        }else{
            if(k < (x[j].fi - x[j - 1].fi) * s){
                ans -= k / s;
                return cout << ans , 0;
            }else{
                ans -= (x[j].fi - x[j - 1].fi);
                k -= (x[j].fi - x[j - 1].fi) * s;
                s += x[j - 1].se;
                --j;
            }
        }
    }
    cout << ans;
    return 0;
}
