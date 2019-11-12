///not today

#include<bits/stdc++.h>
using namespace std;

#define SZ(x) (int)(x).size()
#define pb push_back
#define ll long long
#define xmax(x, y) (x) = max((x), (y))
#define xmin(x, y) (x) = min((x), (y))
#define F first
#define S second
#define pii pair<int, int>
#define pll pair<long long, long long>
#define int long long
#define pipii pair<int, pair<int, int> >
#define pf push_front

const int maxn = 2000 + 5;
vector <int> v;

int32_t main(){
    int Q;
    cin >>Q;
    while(Q --){
        int n;
        string s, t;
        cin >>n >>s >>t;
        v.clear();
        for(int i = 0; i < n; i ++){
            if(s[i] != t[i]){
                v.pb(i);
            }
        }
        if(SZ(v) != 0 and SZ(v) != 2){
            cout <<"No" <<'\n';
        }
        else{
            if(SZ(v) == 0 or (s[v[0]] == s[v[1]] and t[v[0]] == t[v[1]]))
                cout <<"Yes" <<'\n';
            else
                cout <<"No" <<'\n';
        }
    }
    return false;
}
