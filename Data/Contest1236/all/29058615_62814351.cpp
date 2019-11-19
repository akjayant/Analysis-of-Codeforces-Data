#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<pll,ll> plll;
typedef pair<pll,pll> ppll;
typedef long double ld;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define fst first
#define snd second
#define ins insert
#define pb push_back

const int N = 5e5 + 5;
const int MOD = 1e9 + 7;
map<int,set<int> > mpr,mpc;
vector<pll> kr;
int u = 0,d,l = 0,r,nl,nr,nu,nd;
void check(int x1,int y1,int x2,int y2){
    for(ll i = x1;i <= x2; ++i){
        for(ll j = y1;j <= y2; ++j){
            if(!binary_search(all(kr),make_pair(i,j))){
                cout << "No";
                exit(0);
            }
            mpr[i].erase(j);
            mpc[j].erase(i);
        }
    }
}
ll get(int x,int np){
    if(np == 0){
        if(mpr[x].empty())return -1;
        nr = *mpr[x].begin();
        check(x,*mpr[x].begin(),d - 1,r - 1);
        r = nr;
        return r - 1;
    }
    if(np == 1){
        if(mpc[x].empty())return -1;
        nd = *mpc[x].begin();
        check(*mpc[x].begin(),l + 1,d - 1,x);
        d = nd;
        return d - 1;
    }
    if(np == 2){
        if(mpr[x].empty())return -1;
        nl = *mpr[x].rbegin();
        check(u + 1,l + 1,x,*mpr[x].rbegin());
        l = nl;
        return l + 1;
    }
    if(np == 3){
        if(mpc[x].empty())return -1;
        nu = *mpc[x].rbegin();
        check(u + 1,x,*mpc[x].rbegin(),r - 1);
        u = nu;
        return u + 1;
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    int n,m,k;
    cin >> n >> m >> k;
    d = n + 1,r = m + 1;
    for(int i = 0;i < k; ++i){
        int x,y;
        cin >> x >> y;
        kr.pb({x,y});
    }
    sort(all(kr));
    for(auto &it : kr){
        mpr[it.fst].ins(it.snd);
        mpc[it.snd].ins(it.fst);
    }
    int np = 0;
    while(u <= d || l <= r){
        if(np == 0){get(u + 1,0);u++;}
        if(np == 1){get(r - 1,1);r--;}
        if(np == 2){get(d - 1,2);d--;}
        if(np == 3){get(l + 1,3);l++;}
        np++;
        np %= 4;
    }
    cout << "Yes";
    return 0;
}
/**
5 5 7
2 1
2 2
2 3
2 4
3 4
4 4
4 2
*/
