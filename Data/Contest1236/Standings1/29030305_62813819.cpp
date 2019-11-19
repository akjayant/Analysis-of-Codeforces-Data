#include <bits/stdc++.h>
#define ll long long
#define fr first
#define sc second
#define pii pair<ll,ll>
#define pll pair<ll,ll>
#define vi vector<ll>
#define all(x) (x).begin(),(x).end()
#define mp make_pair

using namespace std;
ll OO = (ll) 1e18 ;
ll Mod = 1e9 + 7;
ll const N = 1e5 + 10;

ll add(ll a,ll b){
    a%=Mod;
    b%=Mod;
    a+=b;
    a%=Mod;
    a+=Mod;
    a%=Mod;
    return a;
}
ll mul(ll a,ll b){
    a%=Mod;
    b%=Mod;
    a*=b;
    a%=Mod;
    a+=Mod;
    a%=Mod;
    return a;
}
ll fpow(ll a,ll p){
    if(p==0)return 1;
    if(p&1)return mul(a,fpow(a,p-1));
    return fpow(mul(a,a),p>>1);
}
set<ll> sex[N],sey[N];
map<int,int> have[N];
ll cnt;
void insert(ll x,ll y){
    sex[x].insert(y);
    sey[y].insert(x);
    have[x][y] = 1;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin.exceptions(cin.failbit);
#ifdef LOCAL
    freopen("in.in", "r", stdin);
#endif
    ll n,m,k;
    cin >> n >> m >> k;
    for(ll i=0;i<k;i++){
        ll x,y;
        cin >> x >> y;
        insert(x,y);
    }
    ll cx = 1,cy = 1,cd = 1;
    ll mnx = 1,mny = 1;
    ll mxx = n,mxy = m;
    while(mnx <= mxx && mny <= mxy){
        if(have[cx][cy])break;
        if(cd == 1){
            mnx++;
            auto it = sex[cx].lower_bound(cy);
            if(it != sex[cx].end() && *it <= mxy) mxy = *it - 1;
            cnt+=mxy - cy + 1;
            cx++;
            cy = mxy;
        }
        else if(cd == 2){
            mxy--;
            auto it = sey[cy].lower_bound(cx);
            if(it !=sey[cy].end() && *it <= mxx)mxx = *it - 1;
            cnt+=mxx - cx + 1;
            cy--;
            cx = mxx;
        }
        else if(cd == 3){
            mxx--;
            auto it = sex[cx].lower_bound(cy);
            if(it!=sex[cx].begin()){
                it--;
                if(*it >= mny)mny = *it + 1;
            }
            cnt+=cy - mny + 1;
            cx--;
            cy = mny;
        }
        else if(cd==4){
            mny++;
            auto it = sey[cy].lower_bound(cx);
            if(it != sey[cy].begin()){
                it--;
                if(*it >= mnx)mnx = *it + 1;
            }
            cnt+=cx - mnx + 1;
            cy++;
            cx = mnx;
        }
        cd = cd + 1;
        if(cd == 5) cd = 1;
    }
    puts(n * m - k <= cnt ? "YES":"NO");
}
