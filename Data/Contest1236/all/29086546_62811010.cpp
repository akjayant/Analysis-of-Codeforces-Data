#include <bits/stdc++.h>
using namespace std;
#define all(a) a.begin(),a.end()
#define sz(a) ((int)(a).size())
//#define ONLINE_JUDGE
#ifdef ONLINE_JUDGE
    #define DEBUG 0
#else
    #define DEBUG 1
#endif
#define debug(a) if(DEBUG) cout<<#a<<" = "<<(a)<<endl
#define x first
#define y second
#define Time ((long long)(clock()*1000/CLOCKS_PER_SEC))
template<typename T>ostream&operator<<(ostream&os,vector<T>a){os<<"( ";for(T&x:a)os<<x<<" ";os<<")"<<endl;return os;}
template<typename T>ostream&operator<<(ostream&os,set<T>a){os<<"( ";for(T x:a)os<<x<<" ";os<<")"<<endl;return os;}
template<typename T>ostream&operator<<(ostream&os,stack<T>a){vector<T>b;while(sz(a))b.push_back(a.back()),a.pop();reverse(all(b));os<<b;return os;}
template<typename T>ostream&operator<<(ostream&os,queue<T>a){vector<T>b;while(sz(a))b.push_back(a.front()),a.pop();os<<b;return os;}
template<typename T>ostream&operator<<(ostream&os,priority_queue<T>a){vector<T>b;while(sz(a))b.push_back(a.top()),a.pop();os<<b;return os;}
template<typename X,typename Y>ostream&operator<<(ostream&os,pair<X,Y>a){os<<"("<<a.first<<" "<<a.second<<")";os.flush();return os;}
template<typename T>ostream&operator<<(ostream&os,complex<T>a){os<<"(r="<<a.real()<<" i="<<a.imag()<<") ";os.flush();return os;}
template<typename X,typename Y>pair<X,Y>&operator-=(pair<X,Y>&A,pair<X,Y>B){A.x-=B.x;A.y-=B.y;return A;}
template<typename X,typename Y>pair<X,Y>&operator+=(pair<X,Y>&A,pair<X,Y>B){A.x+=B.x;A.y+=B.y;return A;}
//template<typename X,typename Y,typename Z>pair<X,Y>&operator*=(pair<X,Y>&A,Z n){A.x*=n;A.y*=n;return A;}
template<typename X,typename Y>X operator*(pair<X,Y>A,pair<X,Y>B){return A.x*B.x+A.y*B.y;}
template<typename X,typename Y>X operator^(pair<X,Y>A,pair<X,Y>B){return A.x*B.y-A.y*B.x;}
template<typename X,typename Y>X operator^(X a,Y b){return a^=b;}
template<typename X,typename Y>X operator+(X a,Y b){return a+=b;}template<typename X,typename Y>X operator-(X a,Y b){return a-=b;}
template<typename X,typename Y>X operator*(X a,Y b){return a*=b;}template<typename X,typename Y>X operator/(X a,Y b){return a/=b;}
typedef long long ll;typedef double dd;typedef pair<int,int>pii;typedef vector<int>vi;typedef vector<pii>vii;typedef vector<vi>vvi;
const int base=1000000007;
ll power(ll a,ll n,ll mod=base){a=a<0?(mod-(-a)%mod):(a%mod);ll r=1;while(n){if(n&1)r=r*a%mod;a=a*a%mod;n>>=1;}return r;}

void solve(int);

int32_t main(int32_t argc,char** argv){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
    if (argc>1 && freopen(argv[1],"r",stdin));
    if (argc>2 && freopen(argv[2],"w",stdout));
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
    //cin>>t;
    for(int i=1;i<=t;++i) solve(i);
    debug(Time);
    return 0;
}
//================================================================Head=========================================================================//

void solve(int testID){
    int n, m, k;
    cin >> n >> m >> k;
    vvi oInRow(n+2), oInCol(m+2);
    int flag = m == 1;
    for (int i = 0; i < k; ++i){
        int x, y;
        cin >> x >> y;
        oInRow[x].push_back(y);
        oInCol[y].push_back(x);
        flag |= x == 1 && y == 2;
    }
    for (int i = 1; i <= n; ++i){
        oInRow[i].push_back(0);
        oInRow[i].push_back(m+1);
        sort(all(oInRow[i]));
    }
    for (int j = 1; j <= m; ++j){
        oInCol[j].push_back(0);
        oInCol[j].push_back(n+1);
        sort(all(oInCol[j]));
    }
    ll ans = 1;
    for (int x = 1, y = 1, h = 1 + flag, Lx = 0, Hx = n+1, Ly = 0, Hy = m+1; ; h = h % 4 + 1){
        int xx = x, yy = y;
        if (h == 1){
            yy = *upper_bound(all(oInRow[x]), y) - 1;
        }
        if (h == 2){
            xx = *upper_bound(all(oInCol[y]), x) - 1;
        }
        if (h == 3){
            yy = *--lower_bound(all(oInRow[x]), y) + 1;
        }
        if (h == 4){
            xx = *--lower_bound(all(oInCol[y]), x) + 1;
            //debug(oInCol[y]);debug(xx);
        }
        //debug(xx);debug(yy);
        xx = min(xx, max(x, Hx - 1));
        xx = max(xx, min(x, Lx + 1));
        yy = min(yy, max(y, Hy - 1));
        yy = max(yy, min(y, Ly + 1));
        if (xx == x && yy == y){
            break;
        }
        ans += abs(xx - x) + abs(yy - y);
        //debug(xx);debug(yy);cout<<"__"<<endl;
        if (h == 1) Lx = x;
        if (h == 2) Hy = y;
        if (h == 3) Hx = x;
        if (h == 4) Ly = y;
        x = xx, y = yy;
    }
    if (ans == ll(n) * m - k) cout << "Yes\n";
    else cout << "No\n";
}
