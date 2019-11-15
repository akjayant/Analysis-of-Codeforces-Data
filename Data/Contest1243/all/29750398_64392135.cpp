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
vector < pll > ans;

int32_t main(){
    int Q;
    cin >>Q;
    while(Q --){
        int n;
        bool x = true;
        string s, t;
        cin >>n >>s >>t;
        v.clear();
        ans.clear();
        for(int i = 0; i < n; i ++){
            if(s[i] != t[i]){
                v.pb(i);
            }
        }
        for(int i = 0; i < SZ(v); i ++){
            int ii = v[i];
            if(s[ii] != t[ii]){
                bool b = false;
                int y = -1;
                for(int j = i + 1; j < SZ(v); j ++){
                    int jj = v[j];
                    if(s[ii] == s[jj]){
                        y = jj;
                        b = false;
                    }
                    else if(s[ii] == t[jj]){
                        y = jj;
                        b = true;
                    }
                }
                if(y == -1){
                    x = false;
                }
                else{
                    if(b){
                        ans.pb({y + 1, y + 1});
                        ans.pb({y + 1, ii + 1});
                        swap(s[y], t[y]);
                        swap(t[ii], s[y]);
                    }
                    else{
                        ans.pb({y + 1, ii + 1});
                        swap(t[ii], s[y]);
                    }
                }
            }
        }
        if(!x)
            cout <<"No" <<'\n';
        else{
            cout <<"Yes" <<'\n' <<SZ(ans) <<'\n';
            for(int i = 0; i < SZ(ans); i ++){
                cout <<ans[i].F <<' ' <<ans[i].S <<'\n';
            }
        }
    }
    return false;
}
