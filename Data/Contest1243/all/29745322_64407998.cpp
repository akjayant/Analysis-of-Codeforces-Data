#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef vector<long long int> vl;
typedef vector<vector<int>> vvi;
typedef vector<vector<long long int>> vvl;
typedef pair<int, int> pii;
typedef pair<long long int, long long int> pll;
typedef vector<pair<int, int>> vii;
typedef vector<pair<long long int, long long int>> vll;
#define fast() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define test() long long int t; cin >> t; cin.ignore(); while(t--) 
#define ff first
#define ss second
#define pb push_back
#define pf push_front
#define mp make_pair
#define MOD 1000000007
#define SMOD 998244353
#define pq priority_queue
#define all(x) x.begin(),x.end()
#define SP(x) setprecision(x)
#define sp " "
#define inp(a) ll a;cin>>a;cin.ignore()
#define inps(a,b) ll a,b;cin>>a>>b;cin.ignore()
#define out(a) cout<<SP(20)<<a<<'\n'
#define outs(a,b) cout<<SP(20)<<a<<" "<<b<<'\n'
#define ins insert
#define er erase
#define lb lower_bound
#define ub upper_bound
#define printclock cerr<<"Time : "<<1000*(ld)clock()/(ld)CLOCKS_PER_SEC<<"ms\n";
#define inpa(a,n) ll a[n]; for(int i=0; i<n; i++){cin>>a[i];}
#define inpv(a,n) vl a; for(int i=0; i<n; i++){inp(x);a.pb(x);}
#define outa(a,n) for(int i=0;i<n;i++){cout<<a[i]<<" ";}cout<<'\n';
#define outv(v) for(auto i:v){cout<<i<<" ";}cout<<'\n';
set<char> vow = {'a','e','i','o','u','A','E','I','O','U'};
bool check1;
ld xpow(ld n, ll m){if(m==0){return 1;}else{ld x = xpow(n, m/2);if(m&1){ld res = x*x*n;if(res>1e7){check1=1;};return res;}else{ld res = x*x;if(res>1e7){check1=1;}return res;}}}
ll xmod(ll a, ll m){return (((a%m)+m)%m);}
ll xmodpow(ll n, ll m, ll y){if(m==0){return 1;}else{ll x = xmodpow(n, m/2, y);if(m&1){return xmod((xmod((xmod(x,y)*xmod(x,y)),y)*xmod(n,y)),y);}else{return xmod((xmod(x,y)*xmod(x,y)),y);}}}

int main(){
    fast();

/* you get what you work for not what you wish for */
    
    test(){
        int n;
        cin >> n;
        string s, r;
        cin >> s >> r;
        int a[26]={0};
        char x[n], y[n];
        int l = 0;
        for(auto i:s){
            a[i-'a']++;
            x[l] = i;
            l++;
        }
        l = 0;
        for(auto i:r){
            a[i-'a']++;
            y[l] = i;
            l++;
        }
        bool check = true;
        for(int i=0; i<26; i++){
            if(a[i]&1){
                check = 0;
            }
        }
        if(!check){
            cout << "No" << endl;
            continue;
        }
        cout << "Yes" << endl;
        vll ans;
        ll cnt = 10;
        while(cnt--){
            for(int i=0; i<n; i++){
                if(x[i]==y[i]){
                    continue;
                }
                char c = x[i];
                ll ind = -1;
                for(int j=0; j<n; j++){
                    if(x[j]==c&&y[j]!=c&&j!=i){
                        ind = j;
                        break;
                    }
                }
                if(ind==-1){
                    for(int j=0; j<n; j++){
                        if(y[j]==c&&x[j]!=c&&j!=i){
                            ind = j;
                            break;
                        }
                    }
                    ans.pb({ind+1, ind+1});
                    swap(x[ind], y[ind]);
                    swap(y[i], x[ind]);
                    ans.pb({ind+1, i+1});
                }
                else{
                    ans.pb({ind+1, i+1});
                    swap(y[i], x[ind]);
                }
            }
        }
        cout << ans.size() << endl;
        for(auto i:ans){
            cout << i.ff << " " << i.ss << endl;
        }
    }
}